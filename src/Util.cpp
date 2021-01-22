#include "pch.h"
#include "Util.h"
#include "ScriptExtender.hpp"
#include "vendor/imgui/stb_image.h"

void Util::ConvertToProperCase(CScriptThread *thread, char *text)
{
    ScriptExData *data = ScriptExData::Get(thread);

    if (data->text_case == CAPITAL_CASE)
    {
        text[0]= toupper(text[0]);

        for(int i=1;text[i]!='\0';i++)
            text[i] = tolower(text[i]);
    }

    if (data->text_case == LOWER_CASE)
    {
        for(int i=0;text[i]!='\0';i++)
            text[i] = tolower(text[i]);
    }

    if (data->text_case == TITLE_CASE)
    {
        text[0] = toupper(text[0]);
        for(int i=1;text[i]!='\0';i++)
        {
            if(text[i-1] != ' ')
                text[i] = tolower(text[i]);
        }
    }
    
};

static bool LoadTextureFromFileDx11(const char* filename, ID3D11ShaderResourceView** out_srv)
{
	// Load from disk into a raw RGBA buffer
	int image_width = 0;
	int image_height = 0;
	unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
	if (image_data == NULL)
		return false;

	// Create texture
	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Width = image_width;
	desc.Height = image_height;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.SampleDesc.Count = 1;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags = 0;

	ID3D11Texture2D *pTexture = NULL;
	D3D11_SUBRESOURCE_DATA subResource;
	subResource.pSysMem = image_data;
	subResource.SysMemPitch = desc.Width * 4;
	subResource.SysMemSlicePitch = 0;

	reinterpret_cast<ID3D11Device*>(Globals::device)->CreateTexture2D(&desc, &subResource, &pTexture);

	// Create texture view
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = desc.MipLevels;
	srvDesc.Texture2D.MostDetailedMip = 0;
	reinterpret_cast<ID3D11Device*>(Globals::device)->CreateShaderResourceView(pTexture, &srvDesc, out_srv);
	pTexture->Release();

	stbi_image_free(image_data);

	return true;
}

void* Util::LoadTextureFromPath(const char *path)
{
    void *texture = NULL;

    if (Globals::renderer == Render_DirectX9)
        D3DXCreateTextureFromFileA(GetD3DDevice(),GAME_PATH((char*)path), reinterpret_cast<PDIRECT3DTEXTURE9*>(&texture));
    else
        LoadTextureFromFileDx11(GAME_PATH((char*)path), reinterpret_cast<ID3D11ShaderResourceView**>(&texture));

    return texture;
}

