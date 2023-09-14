#include "Settings.h"

void Settings::LoadSettings()
{
	constexpr auto path = L"Data/SFSE/Plugins/po3_SmartAiming.ini";

	CSimpleIniA ini;
	ini.SetUnicode();

	ini.LoadFile(path);

	ini::get_value(ini, switchOnAim, "Settings", "bSwitchOnAim", nullptr);
	ini::get_value(ini, switchOnDraw, "Settings", "bSwitchOnDraw", nullptr);
	ini::get_value(ini, rememberLastCameraState, "Settings", "bRememberLastCameraState", nullptr);

	(void)ini.SaveFile(path);
}
