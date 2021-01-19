#include "pch.h"
#include "CLEOImGui.h"

void CLEOImGui::ProcessWindow()
{
	if (ImGui::Begin("TEST WINDOW"))
	{
		ImGui::End();
	}
}

CLEOImGui::CLEOImGui()
{
	Hook::window_func = std::bind(&ProcessWindow);

	Events::processScriptsEvent += [this]
	{
		
	};
}

CLEOImGui::~CLEOImGui()
{
}