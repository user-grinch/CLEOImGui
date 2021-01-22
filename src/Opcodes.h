#pragma once
#include "vendor/CLEO.h"

OpcodeResult WINAPI ImGuiBegin(CScriptThread* thread);
OpcodeResult WINAPI ImGuiEnd(CScriptThread* thread);
OpcodeResult WINAPI ImGuiCheckbox(CScriptThread* thread);
OpcodeResult WINAPI ImGuiButton(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSetTextCase(CScriptThread* thread);

OpcodeResult WINAPI ImGuiGetWindowPos(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSetNextWindowPos(CScriptThread* thread);
OpcodeResult WINAPI ImGuiSetWindowPos(CScriptThread* thread);
OpcodeResult WINAPI ImGuiGetWindowSize(CScriptThread* thread);
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