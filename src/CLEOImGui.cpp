#include "pch.h"
#include "CLEOImGui.h"
#include "CRunningScript.h"
#include "Opcodes.h"

FrameData CLEOImGui::frames = []() {};
CLEOImGui cleoimgui;
int CLEOImGui::text_case = CAPITAL_CASE;
bool CLEOImGui::tab_item_begun = false;

void CLEOImGui::DrawImGui()
{
	/*
		Draw all the data of this frame then clear it
	*/
	frames();
	frames.clear();

	// reset flags to default
	text_case = CAPITAL_CASE;
	Hook::show_mouse = false;
	CLEOImGui::tab_item_begun = false;
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

		CLEO_RegisterOpcode(0xF17, ImGuiSliderInt);
		CLEO_RegisterOpcode(0xF18, ImGuiSliderFloat);

		CLEO_RegisterOpcode(0xF19, ImGuiColorEdit);
		CLEO_RegisterOpcode(0xF1A, ImGuiColorPicker);

		CLEO_RegisterOpcode(0xF1B, ImGuiBeginChild);
		CLEO_RegisterOpcode(0xF1C, ImGuiEndChild);

		CLEO_RegisterOpcode(0xF1D, ImGuiInputInt);
		CLEO_RegisterOpcode(0xF1E, ImGuiInputFloat);
		CLEO_RegisterOpcode(0xF1F, ImGuiInputText);
		CLEO_RegisterOpcode(0xF20, ImGuiInputTextMultiline);

		CLEO_RegisterOpcode(0xF21, ImGuiBeginTabBar);
		CLEO_RegisterOpcode(0xF22, ImGuiBeginTabItem);
		CLEO_RegisterOpcode(0xF23, ImGuiEndTabBar);
		CLEO_RegisterOpcode(0xF24, ImGuiEndTabItem);

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