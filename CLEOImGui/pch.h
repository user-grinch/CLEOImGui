#pragma once
#pragma warning(disable:4503 4244 4005)

#define STB_IMAGE_IMPLEMENTATION
#define CLEOImGuiVersion 1.2f

#include <d3d9.h>
#include <d3d11.h>
#include <d3d11Shader.h>
#include <D3dx9tex.h>
#include <D3DX11tex.h>
#include <fstream>
#include <vector>
#include <windows.h>

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"

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
	static ImVec2 m_fScreenSize;
	static bool m_bInit;
	static Renderer renderer;
	static void* device;
};

struct TextureStructure
{
	std::string file_name;
	std::string category_name;
	void *texture = nullptr;
};