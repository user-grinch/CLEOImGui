#pragma once
#pragma warning(disable:4503 4244 4005)

#define STB_IMAGE_IMPLEMENTATION
#define CLEOImGuiVersion 1.0

#include <d3d9.h>
#include <d3d11.h>
#include <d3d11Shader.h>
#include <D3dx9tex.h>
#include <D3DX11tex.h>
#include <fstream>
#include <vector>
#include <windows.h>

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_internal.h"
#include "vendor/imgui/imgui_impl_dx9.h"
#include "vendor/imgui/imgui_impl_dx11.h"
#include "vendor/imgui/imgui_impl_win32.h"

#include "plugin.h"
#include "CRunningScript.h"
#include "ScriptExtender.hpp"

// Globals
using namespace plugin;

enum Renderer
{
	Render_DirectX9,
	Render_DirectX10,
	Render_DirectX11,
	Render_DirectX12,
	Render_OpenGL,
	Render_Unknown,
	Render_Vulkan,
};

struct Globals
{
	static ImVec2 screen_size;
	static bool init_done;
	static Renderer renderer;
	static void* device;
};

struct TextureStructure
{
	std::string file_name;
	std::string category_name;
	void *texture = nullptr;
};

enum TEXT_CASE
{
    CAPITAL_CASE,
    UPPER_CASE,
    LOWER_CASE,
    TITLE_CASE
};

extern std::ofstream flog;