#include "pch.h"
#include "CLEOImGui.h"
#include "vendor/CLEO.h"

void CLEOImGui::ProcessWindow()
{
	if (ImGui::Begin("TEST WINDOW"))
	{
		ImGui::End();
	}
}

CLEOImGui::CLEOImGui()
{
	 //check cleo version
	if (CLEO_GetVersion() >= CLEO_VERSION) {
		//register opcodes
		//CLEO_RegisterOpcode(0x0B10, Script_IntOp_AND);
		Hook::window_func = std::bind(&ProcessWindow);
	}
	else
		MessageBox(HWND_DESKTOP, "An incorrect version of CLEO was loaded.", "CLEOImGui.cleo", MB_ICONERROR);
	
	// static OpcodeResult WINAPI Script_IntOp_AND(CScriptThread* thread)
    //     /****************************************************************
    //     Opcode Format
    //     0B10=3,%3d% = %1d% AND %2d%
    //     ****************************************************************/
    // {
    //     int a = CLEO_GetIntOpcodeParam(thread);
    //     int b = CLEO_GetIntOpcodeParam(thread);

    //     CLEO_SetIntOpcodeParam(thread, a & b);

    //     return OR_CONTINUE;
    // }
}

CLEOImGui::~CLEOImGui()
{
}