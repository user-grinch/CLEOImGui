/*
	Required:
		DirectX 9 SDK
		Plugin SDK
		Visual Studio 2019 (v142)
		Windows SDK
*/

#pragma once
#include "Hook.h"

class CLEOImGui : Hook
{
private:
	static void ProcessWindow();

public:
	CLEOImGui();
	~CLEOImGui();
} cleoimgui;

