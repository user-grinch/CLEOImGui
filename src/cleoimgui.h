/*
    CLEOImGui - ImGui library bindings for CLEO
    Author: Grinch_

	Required to compile,
		CLEO SDK
		DirectX 9 & 11 SDK
		Plugin SDK
		Build Tools 19
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
	static float m_fImGuiVersion;
	static float m_fFontSize;

	CLEOImGui();
};