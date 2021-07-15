#include "pch.h"

ImVec2 Globals::m_fScreenSize = ImVec2(-1, -1);
bool Globals::m_bInit = false;
Renderer Globals::renderer = Render_Unknown;
void *Globals::device = nullptr;
