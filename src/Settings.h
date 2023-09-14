#pragma once

class Settings : public ISingleton<Settings>
{
public:
	void LoadSettings();

	bool switchOnDraw{ false };
	bool switchOnAim{ true };
	bool rememberLastCameraState{ true };
};
