#pragma once
#pragma warning(disable:4503 4244 4005)

#define STB_IMAGE_IMPLEMENTATION
#define CLEOImGuiVersion 1.3f

#include <d3d9.h>
#include <d3d11.h>
#include <d3d11Shader.h>
#include <D3dx9tex.h>
#include <D3DX11tex.h>
#include <fstream>
#include <vector>
#include <windows.h>

#include "../depend/imgui/imgui.h"
#include "../depend/imgui/imgui_internal.h"
#include "../depend/imgui/imgui_impl_dx9.h"
#include "../depend/imgui/imgui_impl_dx11.h"
#include "../depend/imgui/imgui_impl_win32.h"

#include "plugin.h"
#include "CRunningScript.h"
#include "scriptextender.hpp"

using namespace plugin;

enum eRenderer
{
	Render_DirectX9,
	Render_DirectX11,
	Render_Unknown
};

static eRenderer gRenderer = Render_Unknown;
static void* gpDevice = nullptr;

struct TextureStructure
{
	std::string file_name;
	std::string category_name;
	void *texture = nullptr;
};