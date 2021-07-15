/*
    CLEOImGui - ImGui library ported to CLEO
    Author: Grinch_

	Required to compile,
		CLEO SDK
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
	static void DrawImGui();
	static void RegisterOpcodes();

public:
	static float imgui_version;
	static float font_size;

	CLEOImGui();
};