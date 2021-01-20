#include "pch.h"

ImVec2 Globals::screen_size = ImVec2(-1, -1);
bool Globals::init_done = false;
Renderer Globals::renderer = Render_Unknown;
void *Globals::device = nullptr;

std::ofstream flog = std::ofstream("CLEOImGui.log");
