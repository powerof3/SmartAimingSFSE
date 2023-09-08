#include "RE.h"
#include "Settings.h"

#include "SFSE/Stub.h"

namespace Handler
{
	namespace util
	{
		std::uint32_t get_camera_state()
		{
			return *dku::Hook::adjust_pointer<std::uint32_t>((*RE::playerCamera)->cameraState, 0x50);
		}

		bool is_in_third_person()
		{
			return get_camera_state() == 19;
		}

		bool is_in_first_person()
		{
			return get_camera_state() == 0;
		}
	}

    struct WeaponDraw
	{
		static bool thunk(RE::Actor* a_actor)
		{
			const auto result = func(a_actor);
			if (a_actor->formID == 0x14 && util::is_in_third_person()) {
				RE::ForceFirstPerson(*RE::playerCamera);
			}
			return result;
		}
		static inline std::add_pointer_t<decltype(thunk)> func;
	};

	struct WeaponSheathe
	{
		static bool thunk(RE::Actor* a_actor)
		{
			const auto result = func(a_actor);
			if (a_actor->formID == 0x14 && util::is_in_first_person()) {
				RE::ForceThirdPerson(*RE::playerCamera);
			}
			return result;
		}
		static inline std::add_pointer_t<decltype(thunk)> func;
	};

	struct EnterIronSights
	{
		static bool thunk(std::uintptr_t a_camera, std::uint32_t a_state)
		{
            const auto result = func(a_camera, a_state);
			if (!result && util::is_in_third_person()) {
				RE::ForceFirstPerson(*RE::playerCamera);
			}
			return result;
		}
		static inline std::add_pointer_t<decltype(thunk)> func;
	};

	struct ExitIronSights
	{
		static bool thunk(std::uintptr_t a_camera, std::uint32_t a_state)
		{
            const auto result = func(a_camera, a_state);
			if (!result && util::is_in_first_person()) {
				RE::ForceThirdPerson(*RE::playerCamera);
			}
			return result;
		}
		static inline std::add_pointer_t<decltype(thunk)> func;
	};

	void Install()
	{
        const auto settings = Settings::GetSingleton();

	    if (settings->switchOnDraw) {
			SFSE::AllocTrampoline(28);

	        //WeaponDraw/SheatheHandler
			stl::write_thunk_call<WeaponDraw>(0x025F726C);
			stl::write_thunk_call<WeaponSheathe>(0x025F73A3);

			INFO("Hooked WeaponDraw/Sheathe");
		}

		if (settings->switchOnAim) {
			SFSE::AllocTrampoline(28);

			// if (!playerCamera->QCameraState(0x10)
		    //	Push/PopIronSightMode

		    stl::write_thunk_call<EnterIronSights>(0x025A0114);
			stl::write_thunk_call<ExitIronSights>(0x025A021D);

			INFO("Hooked Enter/ExitIronSights");
		}
	}
}

DLLEXPORT constinit auto SFSEPlugin_Version = []() noexcept {
	SFSE::PluginVersionData data{};

	data.PluginVersion(Plugin::Version);
	data.PluginName(Plugin::NAME);
	data.AuthorName(Plugin::AUTHOR);
	data.UsesSigScanning(true);
	//data.UsesAddressLibrary(true);
	data.HasNoStructUse(true);
	//data.IsLayoutDependent(true);
	data.CompatibleVersions({ RUNTIME_VERSION_1_7_23 });

	return data;
}();

namespace
{
	void MessageCallback(SFSE::MessagingInterface::Message* a_msg) noexcept
	{
		switch (a_msg->type) {
		case SFSE::MessagingInterface::kPostLoad:
			{
				Settings::GetSingleton()->LoadSettings();
		        Handler::Install();
			}
			break;
		default:
			break;
		}
	}
}

/**
// for preload plugins
void SFSEPlugin_Preload(SFSE::LoadInterface* a_sfse);
/**/

DLLEXPORT bool SFSEAPI SFSEPlugin_Load(SFSEInterface* a_sfse)
{
#ifndef NDEBUG
	while (!IsDebuggerPresent()) {
		Sleep(100);
	}
#endif

	SFSE::Init(a_sfse);

	DKUtil::Logger::Init(Plugin::NAME, std::to_string(Plugin::Version));

	INFO("{} v{} loaded", Plugin::NAME, Plugin::Version);

	SFSE::GetMessagingInterface()->RegisterListener(MessageCallback);

	return true;
}