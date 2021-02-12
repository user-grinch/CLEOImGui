#pragma once
#include "CLEO.h"

OpcodeResult WINAPI ImGuiBegin(CScriptThread* thread);
OpcodeResult WINAPI ImGuiEnd(CScriptThread* thread);
OpcodeResult WINAPI ImGuiCheckbox(CScriptThread* thread);
OpcodeResult WINAPI ImGuiButton(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetFontSize(CScriptThread* thread);

OpcodeResult WINAPI ImGuiSetNextWindowPos(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSetWindowPos(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSetNextWindowSize(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSetWindowSize(CScriptThread* thread);
OpcodeResult WINAPI ImGuiShowDemoWindow(CScriptThread* thread);
OpcodeResult WINAPI ImGuiShowStyleEditor(CScriptThread* thread);

OpcodeResult WINAPI ImGuiText(CScriptThread* thread);
OpcodeResult WINAPI ImGuiTextWrapped(CScriptThread* thread);
OpcodeResult WINAPI ImGuiTextDisabled(CScriptThread* thread);
OpcodeResult WINAPI ImGuiTextColored(CScriptThread* thread);

OpcodeResult WINAPI ImGuiColumns(CScriptThread* thread);
OpcodeResult WINAPI ImGuiNextColumn(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSpacing(CScriptThread* thread);
OpcodeResult WINAPI ImGuiDummy(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSameLine(CScriptThread* thread);

OpcodeResult WINAPI ImGuiSliderInt(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSliderFloat(CScriptThread* thread);

OpcodeResult WINAPI ImGuiColorEdit(CScriptThread* thread);
OpcodeResult WINAPI ImGuiColorPicker(CScriptThread* thread);

OpcodeResult WINAPI ImGuiBeginChild(CScriptThread* thread);
OpcodeResult WINAPI ImGuiEndChild(CScriptThread* thread);

OpcodeResult WINAPI ImGuiInputInt(CScriptThread* thread);
OpcodeResult WINAPI ImGuiInputFloat(CScriptThread* thread);
OpcodeResult WINAPI ImGuiInputText(CScriptThread* thread);
OpcodeResult WINAPI ImGuiInputTextMultiline(CScriptThread* thread);

OpcodeResult WINAPI ImGuiBeginTabBar(CScriptThread* thread);
OpcodeResult WINAPI ImGuiBeginTabItem(CScriptThread* thread);
OpcodeResult WINAPI ImGuiEndTabBar(CScriptThread* thread);
OpcodeResult WINAPI ImGuiEndTabItem(CScriptThread* thread);

OpcodeResult WINAPI ImGuiSeparator(CScriptThread* thread);

OpcodeResult WINAPI ImGuiGetCLEOImGuiVersion(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetVersion(CScriptThread* thread);

OpcodeResult WINAPI ImGuiGetFramerate(CScriptThread* thread);
OpcodeResult WINAPI ImGuiColorButton(CScriptThread* thread);

OpcodeResult WINAPI ImGuiBullet(CScriptThread* thread);
OpcodeResult WINAPI ImGuiBulletText(CScriptThread* thread);
OpcodeResult WINAPI ImGuiNewLine(CScriptThread* thread);

OpcodeResult WINAPI ImGuiSetTooltip(CScriptThread* thread);
OpcodeResult WINAPI ImGuiColorTooltip(CScriptThread* thread);

OpcodeResult WINAPI ImGuiIsItemFocused(CScriptThread* thread);
OpcodeResult WINAPI ImGuiIsItemHovered(CScriptThread* thread);
OpcodeResult WINAPI ImGuiIsItemActivated(CScriptThread* thread);
OpcodeResult WINAPI ImGuiIsItemDeactivated(CScriptThread* thread);
OpcodeResult WINAPI ImGuiIsItemActive(CScriptThread* thread);
OpcodeResult WINAPI ImGuiIsItemClicked(CScriptThread* thread);
OpcodeResult WINAPI ImGuiIsWindowHovered(CScriptThread* thread);
OpcodeResult WINAPI ImGuiIsWindowFocused(CScriptThread* thread);

OpcodeResult WINAPI ImGuiRadioButton(CScriptThread* thread);
OpcodeResult WINAPI ImGuiCollapsingHeader(CScriptThread* thread);
OpcodeResult WINAPI ImGuiProgressBar(CScriptThread* thread);

OpcodeResult WINAPI ImGuiGetWindowPosX(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetWindowPosY(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetWindowWidth(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetWindowHeight(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSelectable(CScriptThread* thread);
OpcodeResult WINAPI ImGuiLoadTexture(CScriptThread* thread);
OpcodeResult WINAPI ImGuiImage(CScriptThread* thread);
OpcodeResult WINAPI ImGuiImageEx(CScriptThread* thread);
OpcodeResult WINAPI ImGuiImageButton(CScriptThread* thread);
OpcodeResult WINAPI ImGuiImageButtonEx(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetGameDir(CScriptThread* thread);
OpcodeResult WINAPI ImGuiInvisibleButton(CScriptThread* thread);

OpcodeResult WINAPI ImGuiDrawListAddCircle(CScriptThread* thread);
OpcodeResult WINAPI ImGuiDrawListAddCircleFilled(CScriptThread* thread);
OpcodeResult WINAPI ImGuiDrawListAddRect(CScriptThread* thread);
OpcodeResult WINAPI ImGuiDrawListAddRectFilled(CScriptThread* thread);
OpcodeResult WINAPI ImGuiDrawListAddRectFilledMultiColor(CScriptThread* thread);
OpcodeResult WINAPI ImGuiDrawListAddText(CScriptThread* thread);
OpcodeResult WINAPI ImGuiDrawListAddTriangle(CScriptThread* thread);
OpcodeResult WINAPI ImGuiDrawListAddTriangleFilled(CScriptThread* thread);

OpcodeResult WINAPI ImGuiBeginMainMenuBar(CScriptThread* thread);
OpcodeResult WINAPI ImGuiEndMainMenuBar(CScriptThread* thread);
OpcodeResult WINAPI ImGuiMenuItem(CScriptThread* thread);

OpcodeResult WINAPI ImGuiStyleColorsClassic(CScriptThread* thread);
OpcodeResult WINAPI ImGuiStyleColorsDark(CScriptThread* thread);
OpcodeResult WINAPI ImGuiStyleColorsDefault(CScriptThread* thread);
OpcodeResult WINAPI ImGuiStyleColorsLight(CScriptThread* thread);
OpcodeResult WINAPI ImGuiCalcTextHeight(CScriptThread* thread);
OpcodeResult WINAPI ImGuiCalcTextWidth(CScriptThread* thread);

OpcodeResult WINAPI ImGuiGetStyle(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetStyleInt(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSetStyle(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSetStyleInt(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetColor(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSetColor(CScriptThread* thread);

OpcodeResult WINAPI ImGuiPushItemWidth(CScriptThread* thread);
OpcodeResult WINAPI ImGuiPopItemWidth(CScriptThread* thread);
OpcodeResult WINAPI ImGuiPushItemFlag(CScriptThread* thread);
OpcodeResult WINAPI ImGuiPopItemFlag(CScriptThread* thread);

OpcodeResult WINAPI ImGuiGetWindowContentRegionWidth(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetFrameHeight(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetFrameHeightWithSpacing(CScriptThread* thread);