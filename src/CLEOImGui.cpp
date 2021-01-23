#include "pch.h"
#include "CLEOImGui.h"
#include "Opcodes.h"
#include "Util.h"

std::vector<ScriptExData*> ScriptExData::scripts;
bool ScriptExData::show_cursor = false;

void CLEOImGui::DrawImGui()
{
	// reset the cursor
	ScriptExData::show_cursor = false;
	Util::StyleColorsDefault(); // reset style

	// draw frames
	ScriptExData::DrawFrames();

	// update cursor state
	Hook::show_mouse = ScriptExData::show_cursor;
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

		CLEO_RegisterOpcode(0xF25, ImGuiSeparator);

		CLEO_RegisterOpcode(0xF26, ImGuiGetCLEOImGuiVersion);
		CLEO_RegisterOpcode(0xF27, ImGuiGetVersion);
		CLEO_RegisterOpcode(0xF28, ImGuiGetFramerate);
		CLEO_RegisterOpcode(0xF29, ImGuiColorButton);

		CLEO_RegisterOpcode(0xF2A, ImGuiBullet);
		CLEO_RegisterOpcode(0xF2B, ImGuiBulletText);
		CLEO_RegisterOpcode(0xF2C, ImGuiNewLine);

		CLEO_RegisterOpcode(0xF2D, ImGuiSetTooltip);
		CLEO_RegisterOpcode(0xF2E, ImGuiColorTooltip);

		CLEO_RegisterOpcode(0xF2F, ImGuiIsItemHovered);
		CLEO_RegisterOpcode(0xF30, ImGuiIsItemFocused);
		CLEO_RegisterOpcode(0xF31, ImGuiIsItemActivated);
		CLEO_RegisterOpcode(0xF32, ImGuiIsItemDeactivated);
		CLEO_RegisterOpcode(0xF33, ImGuiIsItemActive);
		CLEO_RegisterOpcode(0xF34, ImGuiIsItemClicked);
		CLEO_RegisterOpcode(0xF35, ImGuiIsWindowHovered);
		CLEO_RegisterOpcode(0xF36, ImGuiIsWindowFocused);

		CLEO_RegisterOpcode(0xF37, ImGuiRadioButton);
		CLEO_RegisterOpcode(0xF38, ImGuiCollapsingHeader);
		CLEO_RegisterOpcode(0xF39, ImGuiProgressBar);

		CLEO_RegisterOpcode(0xF3A, ImGuiGetWindowPosX);
		CLEO_RegisterOpcode(0xF3B, ImGuiGetWindowPosY);
		CLEO_RegisterOpcode(0xF3C, ImGuiGetWindowWidth);
		CLEO_RegisterOpcode(0xF3D, ImGuiGetWindowHeight);

		CLEO_RegisterOpcode(0xF3E, ImGuiSelectable);
		CLEO_RegisterOpcode(0xF3F, ImGuiCombo);
		CLEO_RegisterOpcode(0xF40, ImGuiLoadTexture);
		CLEO_RegisterOpcode(0xF41, ImGuiImage);
		CLEO_RegisterOpcode(0xF42, ImGuiImageEx);
		CLEO_RegisterOpcode(0xF43, ImGuiImageButton);
		CLEO_RegisterOpcode(0xF44, ImGuiImageButtonEx);
		CLEO_RegisterOpcode(0xF45, ImGuiGetGameDir);
		CLEO_RegisterOpcode(0xF46, ImGuiInvisibleButton);

		CLEO_RegisterOpcode(0xF47, ImGuiDrawListAddCircle);
		CLEO_RegisterOpcode(0xF48, ImGuiDrawListAddCircleFilled);
		CLEO_RegisterOpcode(0xF49, ImGuiDrawListAddRect);
		CLEO_RegisterOpcode(0xF4A, ImGuiDrawListAddRectFilled);
		CLEO_RegisterOpcode(0xF4B, ImGuiDrawListAddRectFilledMultiColor);
		CLEO_RegisterOpcode(0xF4C, ImGuiDrawListAddText);
		CLEO_RegisterOpcode(0xF4D, ImGuiDrawListAddTriangle);
		CLEO_RegisterOpcode(0xF4E, ImGuiDrawListAddTriangleFilled);

		CLEO_RegisterOpcode(0xF4F, ImGuiBeginMainMenuBar);
		CLEO_RegisterOpcode(0xF50, ImGuiEndMainMenuBar);
		CLEO_RegisterOpcode(0xF51, ImGuiMenuItem);
		
		CLEO_RegisterOpcode(0xF52, ImGuiStyleColorsClassic);
		CLEO_RegisterOpcode(0xF53, ImGuiStyleColorsDark);
		CLEO_RegisterOpcode(0xF54, ImGuiStyleColorsDefault);
		CLEO_RegisterOpcode(0xF55, ImGuiStyleColorsLight);

		CLEO_RegisterOpcode(0xF56, ImGuiCalcTextSize);

		CLEO_RegisterOpcode(0xF57, ImGuiGetStyle);
		CLEO_RegisterOpcode(0xF58, ImGuiSetStyle);
		CLEO_RegisterOpcode(0xF59, ImGuiSetStyleInt);
		CLEO_RegisterOpcode(0xF5A, ImGuiGetColor);
		CLEO_RegisterOpcode(0xF5B, ImGuiSetColor);
		
		CLEO_RegisterOpcode(0xF5C, ImGuiPushItemWidth);
		CLEO_RegisterOpcode(0xF5D, ImGuiPopItemWidth);
		CLEO_RegisterOpcode(0xF5E, ImGuiPushItemFlag);
		CLEO_RegisterOpcode(0xF5F, ImGuiPopItemFlag);

		Hook::window_func = std::bind(&DrawImGui);
	}
	else
		MessageBox(HWND_DESKTOP, "An incorrect version of CLEO was loaded.", "CLEOImGui.cleo", MB_ICONERROR);
	
}