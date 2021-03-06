#include "MiniginPCH.h"
#include "ResourceManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Renderer.h"
#include "Texture2D.h"
#include "Font.h"

void engine::ResourceManager::Init(std::string&& dataPath)
{
	mDataPath = std::move(dataPath);

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) 
	{
		throw std::runtime_error(std::string("Failed to load support for png's: ") + SDL_GetError());
	}

	if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG) 
	{
		throw std::runtime_error(std::string("Failed to load support for jpg's: ") + SDL_GetError());
	}

	if (TTF_Init() != 0) 
	{
		throw std::runtime_error(std::string("Failed to load support for fonts: ") + SDL_GetError());
	}
}

std::shared_ptr<engine::Texture2D> engine::ResourceManager::LoadTexture(const std::string& file)
{
	std::string fullPath = mDataPath + file;
	SDL_Texture *texture = IMG_LoadTexture(Renderer::GetInstance().GetSDLRenderer(), fullPath.c_str());
	if (texture == nullptr) 
	{
		throw std::runtime_error(std::string("Failed to load texture: " + fullPath) + SDL_GetError());
	}
	auto tex = std::make_shared<Texture2D>(texture);
	tex->SetInitialized(true);

	return tex;
}

std::shared_ptr<engine::Font> engine::ResourceManager::LoadFont(const std::string& file, unsigned int size)
{
	return std::make_shared<Font>(mDataPath + file, size);
}
