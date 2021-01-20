#include "pch.h"
#include "CLEOImGui.h"
#include "vendor/CLEO.h"

FrameData CLEOImGui::frame = []() {};

void CLEOImGui::DrawImGui()
{
	/*
		Draw all the data of this frame then clear it
	*/
	frame();
	frame.clear();
}

OpcodeResult WINAPI ImGuiBegin(CScriptThread* thread);
OpcodeResult WINAPI ImGuiEnd(CScriptThread* thread);

CLEOImGui::CLEOImGui()
{
	//check cleo version
	if (CLEO_GetVersion() >= CLEO_VERSION) {
		//register opcodes
		CLEO_RegisterOpcode(0xF01, ImGuiBegin);
		CLEO_RegisterOpcode(0xF02, ImGuiEnd);
		Hook::window_func = std::bind(&DrawImGui);
	}
	else
		MessageBox(HWND_DESKTOP, "An incorrect version of CLEO was loaded.", "CLEOImGui.cleo", MB_ICONERROR);
	
}

static OpcodeResult WINAPI ImGuiBegin(CScriptThread* thread)
{
	char buf[100];
	CLEO_ReadStringOpcodeParam(thread, buf, sizeof(buf));
	DWORD flags = CLEO_GetIntOpcodeParam(thread);
	
	CLEOImGui::frame += [buf, flags](){
		ImGui::Begin(buf,NULL,flags);
	};
	return OR_CONTINUE;
}

static OpcodeResult WINAPI ImGuiEnd(CScriptThread* thread)
{
	//flog << "ImGuiEnd called" << std::endl;
	CLEOImGui::frame += [](){
		ImGui::End();
	};
	return OR_CONTINUE;
}

CLEOImGui::~CLEOImGui()
{
}