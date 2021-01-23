#include "pch.h"
#include "Util.h"
#include "Opcodes.h"

OpcodeResult WINAPI ImGuiBegin(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	bool* state = (bool*)CLEO_GetPointerToScriptVariable(thread);
	DWORD flags = CLEO_GetIntOpcodeParam(thread);
	DWORD show_mouse = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

	if (show_mouse)
		ScriptExData::show_cursor = true;

    data->imgui += [data, state, buf, flags, show_mouse]()
	{	
		data->show_cursor = show_mouse;
		data->prev_frame[buf] = ImGui::Begin(buf,state,flags);
	};

	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiCheckbox(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	SCRIPT_VAR* state = CLEO_GetPointerToScriptVariable(thread);
	
	ScriptExData *data = ScriptExData::Get(thread);

	data->imgui += [data, buf, state]()
	{
		data->prev_frame[buf] = ImGui::Checkbox(buf, (bool*)state);
	};

	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiButton(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	float size_x = CLEO_GetFloatOpcodeParam(thread);
	float size_y = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

	data->imgui += [=](){
		data->prev_frame[buf] = ImGui::Button(buf,ImVec2(size_x,size_y));
	};

	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiInvisibleButton(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	float size_x = CLEO_GetFloatOpcodeParam(thread);
	float size_y = CLEO_GetFloatOpcodeParam(thread);
	int flags =  CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

	data->imgui += [=](){
		data->prev_frame[buf] = ImGui::InvisibleButton(buf,ImVec2(size_x,size_y),flags);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetTextCase(CScriptThread* thread)
{
	ScriptExData *data = ScriptExData::Get(thread);
	data->text_case = CLEO_GetIntOpcodeParam(thread);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiEnd(CScriptThread* thread)
{
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [](){
		ImGui::End();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetWindowPos(CScriptThread* thread)
{
	float* pos_x = (float*)CLEO_GetPointerToScriptVariable(thread);
	float* pos_y = (float*)CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [pos_x, pos_y](){
		ImVec2 pos = ImGui::GetWindowPos();
		*pos_x = pos.x;
		*pos_y = pos.y;
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetWindowPos(CScriptThread* thread)
{
	FLOAT size_x = CLEO_GetIntOpcodeParam(thread);
	FLOAT size_y = CLEO_GetIntOpcodeParam(thread);
	DWORD cond = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [size_x, size_y, cond](){
		ImGui::SetWindowPos(ImVec2(size_x,size_y),cond);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetWindowSize(CScriptThread* thread)
{
	float* size_x = (float*)CLEO_GetPointerToScriptVariable(thread);
	float* size_y = (float*)CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [size_x, size_y](){
		ImVec2 size = ImGui::GetWindowSize();
		*size_x = size.x;
		*size_y = size.y;
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetWindowSize(CScriptThread* thread)
{
	DWORD size_x = CLEO_GetIntOpcodeParam(thread);
	DWORD size_y = CLEO_GetIntOpcodeParam(thread);
	DWORD cond = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [size_x, size_y, cond](){
		ImGui::SetWindowSize(ImVec2(size_x,size_y),cond);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetNextWindowSize(CScriptThread* thread)
{
	FLOAT size_x = CLEO_GetIntOpcodeParam(thread);
	FLOAT size_y = CLEO_GetIntOpcodeParam(thread);
	DWORD cond = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [size_x, size_y, cond](){
		ImGui::SetNextWindowSize(ImVec2(size_x,size_y),cond);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetNextWindowPos(CScriptThread* thread)
{
	FLOAT size_x = CLEO_GetIntOpcodeParam(thread);
	FLOAT size_y = CLEO_GetIntOpcodeParam(thread);
	DWORD cond = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [size_x, size_y, cond](){
		ImGui::SetNextWindowPos(ImVec2(size_x,size_y),cond);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiShowDemoWindow(CScriptThread* thread)
{
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [](){
		ImGui::ShowDemoWindow();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSeparator(CScriptThread* thread)
{
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [](){
		ImGui::Separator();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiShowStyleEditor(CScriptThread* thread)
{
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [](){
		ImGui::ShowStyleEditor();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiText(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [buf](){
		ImGui::Text(buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiTextWrapped(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	
	// fix bug here	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [buf](){
		ImGui::TextWrapped(buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiTextDisabled(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [buf](){
		ImGui::TextDisabled(buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiTextColored(CScriptThread* thread)
{
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);

	FLOAT r = CLEO_GetFloatOpcodeParam(thread);
	FLOAT g = CLEO_GetFloatOpcodeParam(thread);
	FLOAT b = CLEO_GetFloatOpcodeParam(thread);
	FLOAT a = CLEO_GetFloatOpcodeParam(thread);
	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [buf,r,g,b,a](){
		ImGui::TextColored(ImVec4(r,g,b,a), buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiColumns(CScriptThread* thread)
{
	INT count = CLEO_GetIntOpcodeParam(thread);
	INT border = CLEO_GetIntOpcodeParam(thread);
	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [count, border](){
		ImGui::Columns(count, NULL, border);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiNextColumn(CScriptThread* thread)
{
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [](){
		ImGui::NextColumn();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSpacing(CScriptThread* thread)
{
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [](){
		ImGui::Spacing();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiDummy(CScriptThread* thread)
{
	FLOAT pad_x = CLEO_GetIntOpcodeParam(thread);
	FLOAT pad_y = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [pad_x, pad_y](){
		ImGui::Dummy(ImVec2(pad_x,pad_y));
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSameLine(CScriptThread* thread)
{
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [](){
		ImGui::SameLine();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSliderInt(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	int* var = (int*)CLEO_GetPointerToScriptVariable(thread);
	int min = CLEO_GetIntOpcodeParam(thread);
	int max = CLEO_GetIntOpcodeParam(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	int slider_count = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, var, min, max, flags, slider_count]()
	{
		// 1st one is gonna be mostly used
		if (slider_count == 1)
			data->prev_frame[buf] = ImGui::SliderInt(buf, var, min, max, NULL, flags);
		else
		{
			if (slider_count == 2)
				data->prev_frame[buf] = ImGui::SliderInt2(buf, var, min, max, NULL, flags);

			if (slider_count == 3)
				data->prev_frame[buf] = ImGui::SliderInt3(buf, var, min, max, NULL, flags);

			if (slider_count == 4)
				data->prev_frame[buf] = ImGui::SliderInt4(buf, var, min, max, NULL, flags);
		}
			
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSliderFloat(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);

	float* var = (float*)CLEO_GetPointerToScriptVariable(thread);
	float min = CLEO_GetFloatOpcodeParam(thread);
	float max = CLEO_GetFloatOpcodeParam(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	int slider_count = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, var, min, max, flags, slider_count](){

		// 1st one is gonna be mostly used
		if (slider_count == 1)
			data->prev_frame[buf] = ImGui::SliderFloat(buf, var, min, max, NULL, flags);
		else
		{
			if (slider_count == 2)
				data->prev_frame[buf] = ImGui::SliderFloat2(buf, var, min, max, NULL, flags);

			if (slider_count == 3)
				data->prev_frame[buf] = ImGui::SliderFloat3(buf, var, min, max, NULL, flags);

			if (slider_count == 4)
				data->prev_frame[buf] = ImGui::SliderFloat4(buf, var, min, max, NULL, flags);
		}
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiColorEdit(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	float* var = (float*)CLEO_GetPointerToScriptVariable(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	int with_alpha = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, var, flags, with_alpha]()
	{
		if (with_alpha == 1)
			data->prev_frame[buf] = ImGui::ColorEdit4(buf,var,flags);
		else
			data->prev_frame[buf] = ImGui::ColorEdit3(buf,var,flags);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiColorPicker(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	float* var = (float*)CLEO_GetPointerToScriptVariable(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	int with_alpha = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, var, flags, with_alpha]()
	{
		if (with_alpha == 1)
			data->prev_frame[buf] = ImGui::ColorPicker4(buf,var,flags);
		else
			data->prev_frame[buf] = ImGui::ColorPicker3(buf,var,flags);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiBeginChild(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	float size_x = CLEO_GetFloatOpcodeParam(thread);
	float size_y = CLEO_GetFloatOpcodeParam(thread);
	int border = CLEO_GetIntOpcodeParam(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [buf, size_x, size_y, border, flags]()
	{
		ImGui::BeginChild(buf,ImVec2(size_x,size_y),border,flags);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiEndChild(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += []()
	{
		ImGui::EndChild();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiInputInt(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);

	int* var = (int*)CLEO_GetPointerToScriptVariable(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	int count = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, var, flags, count](){

		// 1st one is gonna be mostly used
		if (count == 1)
			data->prev_frame[buf] = ImGui::InputInt(buf,var,flags);
		else
		{
			if (count == 2)
				data->prev_frame[buf] = ImGui::InputInt2(buf,var,flags);

			if (count == 3)
				data->prev_frame[buf] = ImGui::InputInt3(buf,var,flags);

			if (count == 4)
				data->prev_frame[buf] = ImGui::InputInt4(buf,var,flags);
		}
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiInputFloat(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);

	float* var = (float*)CLEO_GetPointerToScriptVariable(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	int count = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, var, flags, count](){

		// 1st one is gonna be mostly used
		if (count == 1)
			data->prev_frame[buf] = ImGui::InputFloat(buf,var,NULL,flags);
		else
		{
			if (count == 2)
				data->prev_frame[buf] = ImGui::InputFloat2(buf,var,NULL,flags);

			if (count == 3)
				data->prev_frame[buf] = ImGui::InputFloat3(buf,var,NULL,flags);

			if (count == 4)
				data->prev_frame[buf] = ImGui::InputFloat4(buf,var,NULL,flags);
		}
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiInputText(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);

	char* var = (char*)CLEO_GetPointerToScriptVariable(thread);
	int var_size = CLEO_GetIntOpcodeParam(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, var, var_size, flags](){
		data->prev_frame[buf] = ImGui::InputText(buf,var,var_size,flags);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiInputTextMultiline(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);

	char* var = (char*)CLEO_GetPointerToScriptVariable(thread);
	int var_size = CLEO_GetIntOpcodeParam(thread);
	float size_x = CLEO_GetFloatOpcodeParam(thread);
	float size_y = CLEO_GetFloatOpcodeParam(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, var, var_size, size_x,size_y, flags](){
		data->prev_frame[buf] = ImGui::InputTextMultiline(buf,var,var_size,ImVec2(size_x,size_y),flags);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiBeginTabBar(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	int flags = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, flags](){
		data->prev_frame[buf] = ImGui::BeginTabBar(buf,flags);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiBeginTabItem(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	int flags = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, flags](){
		data->prev_frame[buf] = ImGui::BeginTabItem(buf,NULL,flags);
	};
	
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiEndTabItem(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [](){
		ImGui::EndTabItem();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiEndTabBar(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [](){
		ImGui::EndTabBar();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetCLEOImGuiVersion(CScriptThread* thread)
{	
	CLEO_SetFloatOpcodeParam(thread, CLEOImGuiVersion);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetVersion(CScriptThread* thread)
{	
	float *var = (float*)CLEO_GetPointerToScriptVariable(thread);
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [var](){
		*var = std::stof(ImGui::GetVersion());
	};

	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetFramerate(CScriptThread* thread)
{	
	int *var = (int*)CLEO_GetPointerToScriptVariable(thread);
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [var]()
	{
		*var = int(ImGui::GetIO().Framerate);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiColorButton(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	float r = CLEO_GetFloatOpcodeParam(thread);
	float g = CLEO_GetFloatOpcodeParam(thread);
	float b = CLEO_GetFloatOpcodeParam(thread);
	float a = CLEO_GetFloatOpcodeParam(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	float width = CLEO_GetFloatOpcodeParam(thread);
	float height = CLEO_GetFloatOpcodeParam(thread);
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf,r,g,b,a,flags,width,height]()
	{
		data->prev_frame[buf] = ImGui::ColorButton(buf,ImVec4(r,g,b,a),flags,ImVec2(width,height));
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiBullet(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += []()
	{
		ImGui::Bullet();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiBulletText(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf]()
	{
		ImGui::BulletText(buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiNewLine(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += []()
	{
		ImGui::NewLine();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetTooltip(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [buf]()
	{
		ImGui::SetTooltip(buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiColorTooltip(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	float r = CLEO_GetFloatOpcodeParam(thread);
	float g = CLEO_GetFloatOpcodeParam(thread);
	float b = CLEO_GetFloatOpcodeParam(thread);
	float a = CLEO_GetFloatOpcodeParam(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [buf,r,g,b,a,flags]()
	{
		const float col[] = {r,g,b,a};
		ImGui::ColorTooltip(buf,&col[0],flags);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiIsItemHovered(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	int flags = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, flags]()
	{
		data->prev_frame[buf] = ImGui::IsItemHovered(flags);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiIsItemFocused(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf]()
	{
		data->prev_frame[buf] = ImGui::IsItemFocused();
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiIsItemActivated(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf]()
	{
		data->prev_frame[buf] = ImGui::IsItemActivated();
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiIsItemDeactivated(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf]()
	{
		data->prev_frame[buf] = ImGui::IsItemDeactivated();
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiIsItemActive(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf]()
	{
		data->prev_frame[buf] = ImGui::IsItemActive();
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiIsItemClicked(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	int btn = CLEO_GetIntOpcodeParam(thread);
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, btn]()
	{
		data->prev_frame[buf] = ImGui::IsItemClicked(btn);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiIsWindowHovered(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	int flags = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);
	
    data->imgui += [data, buf, flags]()
	{
		data->prev_frame[buf] = ImGui::IsWindowHovered(flags);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiIsWindowFocused(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	int flags = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, flags]()
	{
		data->prev_frame[buf] = ImGui::IsWindowFocused(flags);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiRadioButton(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	int *var = (int*)CLEO_GetPointerToScriptVariable(thread);
	int val = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, var, val]()
	{
		data->prev_frame[buf] = ImGui::RadioButton(buf, var, val);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiCollapsingHeader(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	int flags = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, flags]()
	{
		data->prev_frame[buf] = ImGui::CollapsingHeader(buf, flags);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiProgressBar(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	int fraction = CLEO_GetIntOpcodeParam(thread);
	int size_x = CLEO_GetIntOpcodeParam(thread);
	int size_y = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, fraction, size_x, size_y]()
	{
		ImGui::ProgressBar(fraction,ImVec2(size_x, size_y),buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetWindowPosX(CScriptThread* thread)
{	
	float *pos = (float*)CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [pos]()
	{
		*pos = ImGui::GetWindowPos().x;
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetWindowPosY(CScriptThread* thread)
{	
	float *pos = (float*)CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [pos]()
	{
		*pos = ImGui::GetWindowPos().y;
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetWindowWidth(CScriptThread* thread)
{	
	float *width = (float*)CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [width]()
	{
		*width = ImGui::GetWindowWidth();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetWindowHeight(CScriptThread* thread)
{	
	float *height = (float*)CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [height]()
	{
		*height = ImGui::GetWindowHeight();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSelectable(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	int selected = CLEO_GetIntOpcodeParam(thread);
	int flags = CLEO_GetIntOpcodeParam(thread);
	float size_x = CLEO_GetFloatOpcodeParam(thread);
	float size_y = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, flags, size_x, size_y, selected]()
	{
		data->prev_frame[buf] = ImGui::Selectable(buf, selected, flags, ImVec2(size_x,size_y));
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiCombo(CScriptThread* thread)
{	
	char label_buf[256];
	char list_buf[256];
	CLEO_ReadStringOpcodeParam(thread, label_buf, sizeof(label_buf));
	Util::ConvertToProperCase(thread, label_buf);
	int *current_item = (int*)CLEO_GetPointerToScriptVariable(thread);
	CLEO_ReadStringOpcodeParam(thread, list_buf, sizeof(list_buf));
	Util::ConvertToProperCase(thread, list_buf);
	float max_pop_items = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, label_buf, current_item, max_pop_items, list_buf]()
	{
		data->prev_frame[label_buf] = ImGui::Combo(label_buf,current_item,list_buf,max_pop_items);
	};

	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[label_buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiLoadTexture(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	int *texture = (int*)CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [data, buf, texture]()
	{
		*texture = (int)Util::LoadTextureFromPath(buf);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiImageEx(CScriptThread* thread)
{	
	int texture = CLEO_GetIntOpcodeParam(thread);

	float size_x = CLEO_GetFloatOpcodeParam(thread);
	float size_y = CLEO_GetFloatOpcodeParam(thread);

	float uv0_x = CLEO_GetFloatOpcodeParam(thread);
	float uv0_y = CLEO_GetFloatOpcodeParam(thread);

	float uv1_x = CLEO_GetFloatOpcodeParam(thread);
	float uv1_y = CLEO_GetFloatOpcodeParam(thread);

	float r = CLEO_GetFloatOpcodeParam(thread);
	float g = CLEO_GetFloatOpcodeParam(thread);
	float b = CLEO_GetFloatOpcodeParam(thread);
	float a = CLEO_GetFloatOpcodeParam(thread);

	float bor_r = CLEO_GetFloatOpcodeParam(thread);
	float bor_g = CLEO_GetFloatOpcodeParam(thread);
	float bor_b = CLEO_GetFloatOpcodeParam(thread);
	float bor_a = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::Image((ImTextureID)texture,ImVec2(size_x, size_y),ImVec2(uv0_x,uv0_y),ImVec2(uv1_x,uv1_y),ImVec4(r,g,b,a),ImVec4(bor_r,bor_g,bor_b,bor_a));
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiImage(CScriptThread* thread)
{	
	int texture = CLEO_GetIntOpcodeParam(thread);
	float size_x = CLEO_GetFloatOpcodeParam(thread);
	float size_y = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::Image((ImTextureID)texture,ImVec2(size_x, size_y));
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiImageButton(CScriptThread* thread)
{	
	int texture = CLEO_GetIntOpcodeParam(thread);
	float size_x = CLEO_GetFloatOpcodeParam(thread);
	float size_y = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::ImageButton((ImTextureID)texture,ImVec2(size_x, size_y));
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiImageButtonEx(CScriptThread* thread)
{	
	int texture = CLEO_GetIntOpcodeParam(thread);

	float size_x = CLEO_GetFloatOpcodeParam(thread);
	float size_y = CLEO_GetFloatOpcodeParam(thread);

	float uv0_x = CLEO_GetFloatOpcodeParam(thread);
	float uv0_y = CLEO_GetFloatOpcodeParam(thread);

	float uv1_x = CLEO_GetFloatOpcodeParam(thread);
	float uv1_y = CLEO_GetFloatOpcodeParam(thread);

	float pad = CLEO_GetFloatOpcodeParam(thread);
	
	float r = CLEO_GetFloatOpcodeParam(thread);
	float g = CLEO_GetFloatOpcodeParam(thread);
	float b = CLEO_GetFloatOpcodeParam(thread);
	float a = CLEO_GetFloatOpcodeParam(thread);

	float bor_r = CLEO_GetFloatOpcodeParam(thread);
	float bor_g = CLEO_GetFloatOpcodeParam(thread);
	float bor_b = CLEO_GetFloatOpcodeParam(thread);
	float bor_a = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::ImageButton((ImTextureID)texture,ImVec2(size_x, size_y),ImVec2(uv0_x,uv0_y),ImVec2(uv1_x,uv1_y),pad,ImVec4(r,g,b,a),ImVec4(bor_r,bor_g,bor_b,bor_a));
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetGameDir(CScriptThread* thread)
{	
	char* src = (char*)CLEO_GetPointerToScriptVariable(thread);
	char *des = GAME_PATH((char*)"");
	memcpy(src,des,strlen(des)+1);
	// GetStyle
	// SetStyle
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiCalcTextSize(CScriptThread* thread)
{	
	char *cbegin = (char*)CLEO_GetPointerToScriptVariable(thread);
	char *cend = (char*)CLEO_GetPointerToScriptVariable(thread);
	int hide_after_hash = CLEO_GetIntOpcodeParam(thread);
	float word_warp = CLEO_GetFloatOpcodeParam(thread);
	float *width = (float*)CLEO_GetPointerToScriptVariable(thread);
	float *height = (float*)CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImVec2 size = ImGui::CalcTextSize(cbegin,cend,(bool)hide_after_hash,word_warp);

		*width = size.x;
		*height = size.y;
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiDrawListAddText(CScriptThread* thread)
{	
	float pos_x = CLEO_GetFloatOpcodeParam(thread);
	float pos_y = CLEO_GetFloatOpcodeParam(thread);
	float radius = CLEO_GetFloatOpcodeParam(thread);
	int color = CLEO_GetIntOpcodeParam(thread);
	char *cbegin = (char*)CLEO_GetPointerToScriptVariable(thread);
	char *cend = (char*)CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::GetWindowDrawList()->AddText(ImVec2(pos_x,pos_y),color,cbegin,cend);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiDrawListAddCircle(CScriptThread* thread)
{	
	float center_x = CLEO_GetFloatOpcodeParam(thread);
	float center_y = CLEO_GetFloatOpcodeParam(thread);
	float radius = CLEO_GetFloatOpcodeParam(thread);
	int color = CLEO_GetIntOpcodeParam(thread);
	int segments = CLEO_GetFloatOpcodeParam(thread);
	int thickness = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::GetWindowDrawList()->AddCircle(ImVec2(center_x,center_y),radius,color,segments,thickness);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiDrawListAddCircleFilled(CScriptThread* thread)
{	
	float center_x = CLEO_GetFloatOpcodeParam(thread);
	float center_y = CLEO_GetFloatOpcodeParam(thread);
	float radius = CLEO_GetFloatOpcodeParam(thread);
	int color = CLEO_GetIntOpcodeParam(thread);
	int segments = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(center_x,center_y),radius,color,segments);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiBeginMainMenuBar(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += []()
	{
		ImGui::BeginMainMenuBar();
	};

	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiEndMainMenuBar(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += []()
	{
		ImGui::EndMainMenuBar();
	};

	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiMenuItem(CScriptThread* thread)
{	
	char buf[256];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	Util::ConvertToProperCase(thread, buf);
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		data->prev_frame[buf] = ImGui::MenuItem(buf);
	};
	reinterpret_cast<CRunningScript*>(thread)->UpdateCompareFlag(data->prev_frame[buf]);
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiStyleColorsClassic(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += []()
	{
		ImGui::StyleColorsClassic();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiStyleColorsDark(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += []()
	{
		ImGui::StyleColorsDark();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiStyleColorsDefault(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += []()
	{
		Util::StyleColorsDefault();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiStyleColorsLight(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += []()
	{
		ImGui::StyleColorsLight();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiDrawListAddRect(CScriptThread* thread)
{	
	float min_x = CLEO_GetFloatOpcodeParam(thread);
	float min_y = CLEO_GetFloatOpcodeParam(thread);
	float max_x = CLEO_GetFloatOpcodeParam(thread);
	float max_y = CLEO_GetFloatOpcodeParam(thread);
	int color = CLEO_GetIntOpcodeParam(thread);
	float rounding = CLEO_GetFloatOpcodeParam(thread);
	int corners = CLEO_GetIntOpcodeParam(thread);
	int thickness = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::GetWindowDrawList()->AddRect(ImVec2(min_x,min_y),ImVec2(max_x,max_y),color,rounding,corners,thickness);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiDrawListAddRectFilled(CScriptThread* thread)
{	
	float min_x = CLEO_GetFloatOpcodeParam(thread);
	float min_y = CLEO_GetFloatOpcodeParam(thread);
	float max_x = CLEO_GetFloatOpcodeParam(thread);
	float max_y = CLEO_GetFloatOpcodeParam(thread);
	int color = CLEO_GetIntOpcodeParam(thread);
	float rounding = CLEO_GetFloatOpcodeParam(thread);
	int corners = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(min_x,min_y),ImVec2(max_x,max_y),color,rounding,corners);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiDrawListAddRectFilledMultiColor(CScriptThread* thread)
{	
	float min_x = CLEO_GetFloatOpcodeParam(thread);
	float min_y = CLEO_GetFloatOpcodeParam(thread);
	float max_x = CLEO_GetFloatOpcodeParam(thread);
	float max_y = CLEO_GetFloatOpcodeParam(thread);
	int ul = CLEO_GetIntOpcodeParam(thread);
	int ur = CLEO_GetIntOpcodeParam(thread);
	int br = CLEO_GetIntOpcodeParam(thread);
	int bl = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImVec2(min_x,min_y),ImVec2(max_x,max_y),ul,ur,br,bl);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiDrawListAddTriangle(CScriptThread* thread)
{	
	float p1x = CLEO_GetFloatOpcodeParam(thread);
	float p1y = CLEO_GetFloatOpcodeParam(thread);
	float p2x = CLEO_GetFloatOpcodeParam(thread);
	float p2y = CLEO_GetFloatOpcodeParam(thread);
	float p3x = CLEO_GetFloatOpcodeParam(thread);
	float p3y = CLEO_GetFloatOpcodeParam(thread);
	int color = CLEO_GetIntOpcodeParam(thread);
	int thickness = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::GetWindowDrawList()->AddTriangle(ImVec2(p1x,p1y),ImVec2(p2x,p2y),ImVec2(p3x,p3y),color,thickness);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiDrawListAddTriangleFilled(CScriptThread* thread)
{	
	float p1x = CLEO_GetFloatOpcodeParam(thread);
	float p1y = CLEO_GetFloatOpcodeParam(thread);
	float p2x = CLEO_GetFloatOpcodeParam(thread);
	float p2y = CLEO_GetFloatOpcodeParam(thread);
	float p3x = CLEO_GetFloatOpcodeParam(thread);
	float p3y = CLEO_GetFloatOpcodeParam(thread);
	int color = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::GetWindowDrawList()->AddTriangleFilled(ImVec2(p1x,p1y),ImVec2(p2x,p2y),ImVec2(p3x,p3y),color);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetStyle(CScriptThread* thread)
{	
	int index = CLEO_GetIntOpcodeParam(thread);
	SCRIPT_VAR *var = CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGuiStyle *style = &ImGui::GetStyle();
		*var =  *(SCRIPT_VAR*)(int(style) + index);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetStyle(CScriptThread* thread)
{	
	int index = CLEO_GetIntOpcodeParam(thread);
	float val = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGuiStyle *style = &ImGui::GetStyle();
		*(float*)(int(style) + index) = val;
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetStyleInt(CScriptThread* thread)
{	
	int index = CLEO_GetIntOpcodeParam(thread);
	int val = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGuiStyle *style = &ImGui::GetStyle();
		*(int*)(int(style) + index) = val;
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiSetColor(CScriptThread* thread)
{	
	int index = CLEO_GetIntOpcodeParam(thread);
	float r = CLEO_GetFloatOpcodeParam(thread);
	float g = CLEO_GetFloatOpcodeParam(thread);
	float b = CLEO_GetFloatOpcodeParam(thread);
	float a = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::GetStyle().Colors[index] = ImVec4(r,g,b,a);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiGetColor(CScriptThread* thread)
{	
	int index = CLEO_GetIntOpcodeParam(thread);
	float *r = (float*)CLEO_GetPointerToScriptVariable(thread);
	float *g = (float*)CLEO_GetPointerToScriptVariable(thread);
	float *b = (float*)CLEO_GetPointerToScriptVariable(thread);
	float *a = (float*)CLEO_GetPointerToScriptVariable(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImVec4 color = ImGui::GetStyle().Colors[index];

		*r = color.x;
		*g = color.y;
		*b = color.z;
		*a = color.w;
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiPushItemWidth(CScriptThread* thread)
{	
	float val = CLEO_GetFloatOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::PushItemWidth(val);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiPopItemWidth(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::PopItemWidth();
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiPushItemFlag(CScriptThread* thread)
{	
	int state = CLEO_GetIntOpcodeParam(thread);
	int flag = CLEO_GetIntOpcodeParam(thread);

	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{	
		ImGui::PushItemFlag(flag,state);
	};
	return OR_CONTINUE;
}

OpcodeResult WINAPI ImGuiPopItemFlag(CScriptThread* thread)
{	
	ScriptExData *data = ScriptExData::Get(thread);

    data->imgui += [=]()
	{
		ImGui::PopItemFlag();
	};
	return OR_CONTINUE;
}
