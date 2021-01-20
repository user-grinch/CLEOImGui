#pragma once
#pragma warning(disable:4503 4244 4005)

#define INPUT_BUFFER_SIZE 64
#define STB_IMAGE_IMPLEMENTATION

#include <d3d9.h>
#include <d3d11.h>
#include <d3d11Shader.h>
#include <D3dx9tex.h>
#include <D3DX11tex.h>
#include <filesystem>
#include <fstream>
#include <functional>
#include <memory>
#include <sstream>
#include <vector>
#include <windows.h>

#include "plugin.h"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_internal.h"
#include "vendor/imgui/imgui_impl_dx9.h"
#include "vendor/imgui/imgui_impl_dx11.h"
#include "vendor/imgui/imgui_impl_win32.h"

// Globals
typedef std::vector<std::pair<std::string, void(*)(void)>> unsortedMap;
using namespace plugin;
namespace fs = std::filesystem;

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

extern std::ofstream flog;