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
#include "FrameData.hpp"

class CLEOImGui : Hook
{
private:
	static void DrawImGui();

public:
	static FrameData frames;
    static int text_case;
    
    static void ShowMouse(bool show);
	CLEOImGui();
	~CLEOImGui();
};

extern CLEOImGui cleoimgui;

