#include "pch.h"
#include "CLEOImGui.h"
#include "CRunningScript.h"
#include "Opcodes.h"

FrameData CLEOImGui::frames = []() {};
CLEOImGui cleoimgui;
int CLEOImGui::text_case = CAPITAL_CASE;

void CLEOImGui::DrawImGui()
{
	/*
		Draw all the data of this frame then clear it
	*/
	frames();
	frames.clear();
	text_case = CAPITAL_CASE; // reset text case
	Hook::show_mouse = false;
}


CLEOImGui::CLEOImGui()
{
	//check cleo version
	if (CLEO_GetVersion() >= CLEO_VERSION) {
		//register opcodes
		CLEO_RegisterOpcode(0xF01, ImGuiBegin);
		CLEO_RegisterOpcode(0xF02, ImGuiEnd);
		CLEO_RegisterOpcode(0xF03, ImGuiCheckbox);
		CLEO_RegisterOpcode(0xF04, ImGuiButton);
		CLEO_RegisterOpcode(0xF05, ImGuiSetTextCase);

		CLEO_RegisterOpcode(0xF06, ImGuiGetWindowPos);
		CLEO_RegisterOpcode(0xF07, ImGuiSetNextWindowPos);
		CLEO_RegisterOpcode(0xF08, ImGuiSetWindowPos);
		CLEO_RegisterOpcode(0xF09, ImGuiGetWindowSize);
		CLEO_RegisterOpcode(0xF0A, ImGuiSetNextWindowSize);
		CLEO_RegisterOpcode(0xF0B, ImGuiSetWindowSize);

		CLEO_RegisterOpcode(0xF0C, ImGuiShowDemoWindow);
		CLEO_RegisterOpcode(0xF0D, ImGuiShowStyleEditor);

		CLEO_RegisterOpcode(0xF0E, ImGuiText);
		CLEO_RegisterOpcode(0xF0F, ImGuiTextWrapped);
		CLEO_RegisterOpcode(0xF10, ImGuiTextDisabled);
		CLEO_RegisterOpcode(0xF11, ImGuiTextColored);

		CLEO_RegisterOpcode(0xF12, ImGuiColumns);
		CLEO_RegisterOpcode(0xF13, ImGuiNextColumn);
		CLEO_RegisterOpcode(0xF14, ImGuiSpacing);
		CLEO_RegisterOpcode(0xF15, ImGuiDummy);
		CLEO_RegisterOpcode(0xF16, ImGuiSameLine);

		Hook::window_func = std::bind(&DrawImGui);
	}
	else
		MessageBox(HWND_DESKTOP, "An incorrect version of CLEO was loaded.", "CLEOImGui.cleo", MB_ICONERROR);
	
}

void CLEOImGui::ShowMouse(bool show)
{
	Hook::show_mouse = show;
}


CLEOImGui::~CLEOImGui()
{
}