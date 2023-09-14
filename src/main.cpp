#include "Settings.h"

namespace Handler
{
	RE::CameraState lastDrawCameraState;
	RE::CameraState lastAimCameraState;

	float lastZoomOffset;

	namespace detail
	{
		RE::CameraState QCameraState()
		{
			return *stl::adjust_pointer<RE::CameraState>(RE::PlayerCamera::GetSingleton()->currentState, 0x50);
		}
	}

	void TrySetFirstPerson(RE::CameraState& a_cachedCameraState)
	{
		a_cachedCameraState = detail::QCameraState();
		if (const auto playerCamera = RE::PlayerCamera::GetSingleton(); playerCamera->IsInThirdPerson()) {
			playerCamera->ForceFirstPerson();
		}
	}

	void TrySetThirdPerson(RE::CameraState a_cachedCameraState)
	{
		if (const auto playerCamera = RE::PlayerCamera::GetSingleton(); playerCamera->IsInFirstPerson()) {
			if (!Settings::GetSingleton()->rememberLastCameraState || a_cachedCameraState == RE::CameraState::kThirdPerson) {
				playerCamera->ForceThirdPerson();
			}
		}
	}

	struct WeaponDraw
	{
		static bool Thunk(std::uintptr_t a_handler, RE::Actor* a_actor)
		{
			const auto result = func(a_handler, a_actor);
			if (a_actor->IsPlayerRef()) {
				TrySetFirstPerson(lastDrawCameraState);
			}
			return result;
		}
		static inline REL::Relocation<decltype(Thunk)> func;
		static inline std::size_t                      idx{ 0x1 };
	};

	struct EnterIronSights
	{
		static bool Thunk(RE::PlayerCamera* a_camera, std::uint32_t a_state)
		{
			const auto result = func(a_camera, a_state);
			if (!result) {
				TrySetFirstPerson(lastAimCameraState);
			}
			return result;
		}
		static inline REL::Relocation<decltype(Thunk)> func;
		static inline std::uintptr_t                   address{ REL::Relocation<std::uintptr_t>(REL::Offset(0x0259FE2C), 0x128).address() };  // -_-
	};

	struct WeaponSheathe
	{
		static bool Thunk(std::uintptr_t a_handler, RE::Actor* a_actor)
		{
			const auto result = func(a_handler, a_actor);
			if (a_actor->IsPlayerRef()) {
				TrySetThirdPerson(lastDrawCameraState);
			}
			return result;
		}
		static inline REL::Relocation<decltype(Thunk)> func;
		static inline std::size_t                      idx{ 0x1 };
	};

	struct ExitIronSights
	{
		static bool Thunk(RE::PlayerCamera* a_camera, std::uint32_t a_state)
		{
			const auto result = func(a_camera, a_state);
			if (!result) {
				TrySetThirdPerson(lastAimCameraState);
			}
			return result;
		}
		static inline REL::Relocation<decltype(Thunk)> func;
		static inline std::uintptr_t                   address{ REL::Relocation<std::uintptr_t>(REL::Offset(0x0259FE2C), 0x231).address() };  // -_-
	};

	void Install()
	{
		const auto settings = Settings::GetSingleton();

		if (settings->switchOnDraw) {
			stl::write_vfunc<WeaponDraw>(RE::VTABLE::WeaponDrawHandler[0]);
			stl::write_vfunc<WeaponSheathe>(RE::VTABLE::WeaponSheatheHandler[0]);

			logger::info("Hooked WeaponDraw/Sheathe");
		}

		if (settings->switchOnAim) {
			// if (!playerCamera->QCameraState(0x10)
			//	Push/PopIronSightMode

			stl::write_thunk_call<EnterIronSights>();
			stl::write_thunk_call<ExitIronSights>();

			logger::info("Hooked Enter/ExitIronSights");
		}
	}
}

void MessageCallback(SFSE::MessagingInterface::Message* a_msg) noexcept
{
	switch (a_msg->type) {
	case SFSE::MessagingInterface::kPostLoad:
		Handler::Install();
		break;
	default:
		break;
	}
}

DLLEXPORT constinit auto SFSEPlugin_Version = []() noexcept {
	SFSE::PluginVersionData data{};

	data.PluginVersion(Version::MAJOR);
	data.PluginName(Version::PROJECT);
	data.AuthorName("powerofthree");
	data.UsesSigScanning(true);
	//data.UsesAddressLibrary(true);
	data.HasNoStructUse(true);
	//data.IsLayoutDependent(true);
	data.CompatibleVersions({ SFSE::RUNTIME_SF_1_7_29 });

	return data;
}();

DLLEXPORT bool SFSEAPI SFSEPlugin_Load(const SFSE::LoadInterface* a_sfse)
{
	SFSE::Init(a_sfse);

	SFSE::GetMessagingInterface()->RegisterListener(MessageCallback);

	return true;
}
