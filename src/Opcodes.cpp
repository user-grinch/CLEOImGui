#include "pch.h"
#include "CLEOImGui.h"
#include "Util.h"
#include "Opcodes.h"
#include <regex>

OpcodeResult WINAPI ImGuiBegin(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);
	SCRIPT_VAR* state = CLEO_GetPointerToScriptVariable(thread);
	DWORD flags = CLEO_GetIntOpcodeParam(thread);
	DWORD show_mouse = CLEO_GetIntOpcodeParam(thread);
	
	if (show_mouse)
		CLEOImGui::ShowMouse(true);

	CLEOImGui::frames += [state, buf, flags](){
		ImGui::Begin(buf,(bool*)state,flags);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiCheckbox(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);
	SCRIPT_VAR* state = CLEO_GetPointerToScriptVariable(thread);
	
	CLEOImGui::frames += [buf, state](){
		ImGui::Checkbox(buf, (bool*)state);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiButton(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);
	DWORD size_x = CLEO_GetIntOpcodeParam(thread);
	DWORD size_y = CLEO_GetIntOpcodeParam(thread);
	SCRIPT_VAR* clicked = CLEO_GetPointerToScriptVariable(thread);

	CLEOImGui::frames += [buf, size_x, size_y, clicked](){
		bool click = ImGui::Button(buf,ImVec2(size_x,size_y));
		*clicked = SCRIPT_VAR(click);
	};
	
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetTextCase(CScriptThread* thread)
{
	CLEOImGui::text_case = CLEO_GetIntOpcodeParam(thread);
	
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiEnd(CScriptThread* thread)
{
	CLEOImGui::frames += [](){
		ImGui::End();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetWindowPos(CScriptThread* thread)
{
	SCRIPT_VAR* pos_x = CLEO_GetPointerToScriptVariable(thread);
	SCRIPT_VAR* pos_y = CLEO_GetPointerToScriptVariable(thread);

	CLEOImGui::frames += [pos_x, pos_y](){
		ImVec2 pos = ImGui::GetWindowPos();
		*pos_x = SCRIPT_VAR(pos.x);
		*pos_y = SCRIPT_VAR(pos.y);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetWindowPos(CScriptThread* thread)
{
	DWORD size_x = CLEO_GetIntOpcodeParam(thread);
	DWORD size_y = CLEO_GetIntOpcodeParam(thread);
	DWORD cond = CLEO_GetIntOpcodeParam(thread);

	CLEOImGui::frames += [size_x, size_y, cond](){
		ImGui::SetWindowPos(ImVec2(size_x,size_y),cond);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetWindowSize(CScriptThread* thread)
{
	SCRIPT_VAR* size_x = CLEO_GetPointerToScriptVariable(thread);
	SCRIPT_VAR* size_y = CLEO_GetPointerToScriptVariable(thread);

	CLEOImGui::frames += [size_x, size_y](){
		ImVec2 size = ImGui::GetWindowSize();
		*size_x = SCRIPT_VAR(size.x);
		*size_y = SCRIPT_VAR(size.y);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetWindowSize(CScriptThread* thread)
{
	DWORD size_x = CLEO_GetIntOpcodeParam(thread);
	DWORD size_y = CLEO_GetIntOpcodeParam(thread);
	DWORD cond = CLEO_GetIntOpcodeParam(thread);

	CLEOImGui::frames += [size_x, size_y, cond](){
		ImGui::SetWindowSize(ImVec2(size_x,size_y),cond);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetNextWindowSize(CScriptThread* thread)
{
	DWORD size_x = CLEO_GetIntOpcodeParam(thread);
	DWORD size_y = CLEO_GetIntOpcodeParam(thread);
	DWORD cond = CLEO_GetIntOpcodeParam(thread);

	CLEOImGui::frames += [size_x, size_y, cond](){
		ImGui::SetNextWindowSize(ImVec2(size_x,size_y),cond);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetNextWindowPos(CScriptThread* thread)
{
	DWORD size_x = CLEO_GetIntOpcodeParam(thread);
	DWORD size_y = CLEO_GetIntOpcodeParam(thread);
	DWORD cond = CLEO_GetIntOpcodeParam(thread);

	CLEOImGui::frames += [size_x, size_y, cond](){
		ImGui::SetNextWindowPos(ImVec2(size_x,size_y),cond);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiShowDemoWindow(CScriptThread* thread)
{
	CLEOImGui::frames += [](){
		ImGui::ShowDemoWindow();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiShowStyleEditor(CScriptThread* thread)
{
	CLEOImGui::frames += [](){
		ImGui::ShowStyleEditor();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiText(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);

	CLEOImGui::frames += [buf](){
		ImGui::Text(buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiTextWrapped(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);
	
	// fix bug here	
	CLEOImGui::frames += [buf](){
		ImGui::TextWrapped(buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiTextDisabled(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);

	CLEOImGui::frames += [buf](){
		ImGui::TextDisabled(buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiTextColored(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);

	FLOAT r = CLEO_GetFloatOpcodeParam(thread);
	FLOAT g = CLEO_GetFloatOpcodeParam(thread);
	FLOAT b = CLEO_GetFloatOpcodeParam(thread);
	FLOAT a = CLEO_GetFloatOpcodeParam(thread);
	
	CLEOImGui::frames += [buf,r,g,b,a](){
		ImGui::TextColored(ImVec4(r,g,b,a), buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiColumns(CScriptThread* thread)
{
	INT count = CLEO_GetIntOpcodeParam(thread);
	INT border = CLEO_GetIntOpcodeParam(thread);
	
	CLEOImGui::frames += [count, border](){
		ImGui::Columns(count, NULL, border);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiNextColumn(CScriptThread* thread)
{
	CLEOImGui::frames += [](){
		ImGui::NextColumn();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSpacing(CScriptThread* thread)
{
	CLEOImGui::frames += [](){
		ImGui::Spacing();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiDummy(CScriptThread* thread)
{
	INT pad_x = CLEO_GetIntOpcodeParam(thread);
	INT pad_y = CLEO_GetIntOpcodeParam(thread);

	CLEOImGui::frames += [pad_x, pad_y](){
		ImGui::Dummy(ImVec2(pad_x,pad_y));
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSameLine(CScriptThread* thread)
{
	CLEOImGui::frames += [](){
		ImGui::SameLine();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSliderInt(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);
	int* var = (int*)CLEO_GetPointerToScriptVariable(thread);
	int min = CLEO_GetIntOpcodeParam(thread);
	int max = CLEO_GetIntOpcodeParam(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	int slider_count = CLEO_GetIntOpcodeParam(thread);

	CLEOImGui::frames += [buf, var, min, max, flags, slider_count]()
	{
		// 1st one is gonna be mostly used
		if (slider_count == 1)
			ImGui::SliderInt(buf, var, min, max, NULL, flags);
		else
		{
			if (slider_count == 2)
				ImGui::SliderInt2(buf, var, min, max, NULL, flags);

			if (slider_count == 3)
				ImGui::SliderInt3(buf, var, min, max, NULL, flags);

			if (slider_count == 4)
				ImGui::SliderInt4(buf, var, min, max, NULL, flags);
		}
			
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSliderFloat(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);

	float* var = (float*)CLEO_GetPointerToScriptVariable(thread);
	float min = CLEO_GetFloatOpcodeParam(thread);
	float max = CLEO_GetFloatOpcodeParam(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	int slider_count = CLEO_GetIntOpcodeParam(thread);

	CLEOImGui::frames += [buf, var, min, max, flags, slider_count](){

		// 1st one is gonna be mostly used
		if (slider_count == 1)
			ImGui::SliderFloat(buf, var, min, max, NULL, flags);
		else
		{
			if (slider_count == 2)
				ImGui::SliderFloat2(buf, var, min, max, NULL, flags);

			if (slider_count == 3)
				ImGui::SliderFloat3(buf, var, min, max, NULL, flags);

			if (slider_count == 4)
				ImGui::SliderFloat4(buf, var, min, max, NULL, flags);
		}
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiColorEdit(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);
	float* var = (float*)CLEO_GetPointerToScriptVariable(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	int with_alpha = CLEO_GetIntOpcodeParam(thread);

	CLEOImGui::frames += [buf, var, flags, with_alpha]()
	{
		if (with_alpha == 1)
			ImGui::ColorEdit4(buf,var,flags);
		else
			ImGui::ColorEdit3(buf,var,flags);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiColorPicker(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	ConvertToProperCase(buf);
	float* var = (float*)CLEO_GetPointerToScriptVariable(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	int with_alpha = CLEO_GetIntOpcodeParam(thread);

	CLEOImGui::frames += [buf, var, flags, with_alpha]()
	{
		if (with_alpha == 1)
			ImGui::ColorPicker4(buf,var,flags);
		else
			ImGui::ColorPicker3(buf,var,flags);
	};
	return OR_CONTINUE;
}