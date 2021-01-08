#include "Renderer.h"

//TODO quiero una referencia o ahora quiero un nombre ...
//ERROR ....
//const SDL_Rect* Renderer::Rect2SDL(const RECT* r) { return { r->x, r->y, r->w, r->h }; }

Renderer::Renderer()
{
	// SDL --- INIT ---
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw "No es pot inicialitzar SDL subsystems";

	// --- WINDOW ---
	m_window = SDL_CreateWindow("SDL...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if (m_window == nullptr) throw "No es pot inicialitzar SDL_Window";

	// --- RENDERER ---
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr) throw "No es pot inicialitzar SDL_Renderer";

	//Initialize renderer color
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	//IMG --- INIT ---
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_imageinit";

	//TTF --- INIT ---
	if (TTF_Init() != 0) throw"No es pot inicialitzar SDL_ttf";

	Font mainFont{ MAIN_FONT::ID, MAIN_FONT::PATH, MAIN_FONT::SIZE };
	LoadFont(mainFont);

	LoadTexture(GAME::BACKGROUND_ID, GAME::BACKGROUND_PATH);

	Text itemsSpritesheet{ ITEMS_SPRITESHEET::ID, ITEMS_SPRITESHEET::TEXT, ITEMS_SPRITESHEET::COLOR, ITEMS_SPRITESHEET::WIDTH, ITEMS_SPRITESHEET::HEIGHT };
	LoadTexture(itemsSpritesheet.id, ITEMS_SPRITESHEET::PATH);

	Text player1Spritesheet{ PLAYER1_SPRITESHEET::ID, PLAYER1_SPRITESHEET::TEXT, PLAYER1_SPRITESHEET::COLOR, PLAYER1_SPRITESHEET::WIDTH, PLAYER1_SPRITESHEET::HEIGHT };
	LoadTexture(player1Spritesheet.id, PLAYER1_SPRITESHEET::PATH);
	
	Text player2Spritesheet{ PLAYER2_SPRITESHEET::ID, PLAYER2_SPRITESHEET::TEXT, PLAYER2_SPRITESHEET::COLOR, PLAYER2_SPRITESHEET::WIDTH, PLAYER2_SPRITESHEET::HEIGHT };
	LoadTexture(player2Spritesheet.id, PLAYER2_SPRITESHEET::PATH);

	Text explosionSpritesheet{ EXPLOSION_SPRITESHEET::ID, EXPLOSION_SPRITESHEET::TEXT, EXPLOSION_SPRITESHEET::COLOR, EXPLOSION_SPRITESHEET::WIDTH, EXPLOSION_SPRITESHEET::HEIGHT };
	LoadTexture(explosionSpritesheet.id, EXPLOSION_SPRITESHEET::PATH);

	Text map1Button{ MAP1_BUTTON::ID, MAP1_BUTTON::TEXT, MAP1_BUTTON::COLOR, MAP1_BUTTON::W, MAP1_BUTTON::H };
	LoadTextureText(mainFont.id, map1Button);
	Text map1ButtonHover{ MAP1_BUTTON::HOVER_ID, MAP1_BUTTON::TEXT, MAP1_BUTTON::HOVER_COLOR, MAP1_BUTTON::W, MAP1_BUTTON::H };
	LoadTextureText(mainFont.id, map1ButtonHover);

	Text map2Button{ MAP2_BUTTON::ID, MAP2_BUTTON::TEXT, MAP2_BUTTON::COLOR, MAP2_BUTTON::W, MAP2_BUTTON::H };
	LoadTextureText(mainFont.id, map2Button);
	Text map2ButtonHover{ MAP2_BUTTON::HOVER_ID, MAP2_BUTTON::TEXT, MAP2_BUTTON::HOVER_COLOR, MAP2_BUTTON::W, MAP2_BUTTON::H };
	LoadTextureText(mainFont.id, map2ButtonHover);

	Text rankingButton{ RANKING_BUTTON::ID, RANKING_BUTTON::TEXT, RANKING_BUTTON::COLOR, RANKING_BUTTON::W, RANKING_BUTTON::H };
	LoadTextureText(mainFont.id, rankingButton);
	Text rankingButtonHover{ RANKING_BUTTON::HOVER_ID, RANKING_BUTTON::TEXT, RANKING_BUTTON::HOVER_COLOR, RANKING_BUTTON::W, RANKING_BUTTON::H };
	LoadTextureText(mainFont.id, rankingButtonHover);

	Text exitButton{ EXIT_BUTTON::ID, EXIT_BUTTON::TEXT, EXIT_BUTTON::COLOR, EXIT_BUTTON::W, EXIT_BUTTON::H };
	LoadTextureText(mainFont.id, exitButton);
	Text exitButtonHover{ EXIT_BUTTON::HOVER_ID, EXIT_BUTTON::TEXT, EXIT_BUTTON::HOVER_COLOR, EXIT_BUTTON::W, EXIT_BUTTON::H };
	LoadTextureText(mainFont.id, exitButtonHover);

	Text soundButton{ SOUND_BUTTON::ID, SOUND_BUTTON::TEXT, SOUND_BUTTON::COLOR, SOUND_BUTTON::W, SOUND_BUTTON::H };
	LoadTextureText(mainFont.id, soundButton);
	Text soundButtonHover{ SOUND_BUTTON::HOVER_ID, SOUND_BUTTON::TEXT, SOUND_BUTTON::HOVER_COLOR, SOUND_BUTTON::W, SOUND_BUTTON::H };
	LoadTextureText(mainFont.id, soundButtonHover);

};

Renderer::~Renderer()
{
	for (auto &t : m_textureData) SDL_DestroyTexture(t.second), t.second = nullptr;
	for (auto &f : m_fontData) TTF_CloseFont(f.second), f.second = nullptr;
	for (auto& f : m_rects) { delete f.second; f.second = nullptr; };

	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;

	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

};

void Renderer::Clear() { SDL_RenderClear(m_renderer); };

void Renderer::Render() { SDL_RenderPresent(m_renderer); };

void Renderer::LoadFont(const Font &font) {
	TTF_Font *ttfFont{ TTF_OpenFont(font.path.c_str(), font.size) };
	if (ttfFont == nullptr) throw"No espot inicialitzar TTF_Font";
	m_fontData[font.id] = ttfFont;
};

void Renderer::LoadTexture(const std::string &id, const std::string &path) {
	SDL_Texture *texture{ IMG_LoadTexture(m_renderer, path.c_str()) };
	if (texture == nullptr) throw "No s'han pogut crear les textures";
	m_textureData[id] = texture;
};

VEC2 Renderer::LoadTextureText(const std::string &fontId, Text text) {
	SDL_Surface	*tmpSurf = TTF_RenderText_Blended(m_fontData[fontId], text.text.c_str(), SDL_Color{ text.color.r, text.color.g, text.color.b,text.color.a });
	if (tmpSurf == nullptr) throw "Unable to create the SDL text surface";
	m_textureData[text.id] = SDL_CreateTextureFromSurface(m_renderer, tmpSurf); //hace un new
	return { tmpSurf->w,tmpSurf->h };
};

void Renderer::LoadRect(const std::string& idRect, const RECT &rect) {
	m_rects[idRect] = new SDL_Rect{ rect.x,rect.y,rect.w,rect.h };
};

VEC2 Renderer::GetTextureSize(const std::string &id) {
	int w; int h;
	SDL_QueryTexture(m_textureData[id], NULL, NULL,&w, &h);
	return {w, h};
};

//Enseñarle a Aniol
void Renderer::PushImage(const std::string &id, const RECT &rect) {
	SDL_Rect aux;
	aux.x = rect.x;
	aux.y = rect.y;
	aux.w = rect.w;
	aux.h = rect.h;
	SDL_RenderCopy(m_renderer, m_textureData[id], nullptr, &aux);
};

void Renderer::PushSprite(const std::string &id, const RECT &idRectSprite, const RECT &idRectPos) {
	SDL_Rect aux1;
	aux1.x = idRectSprite.x;
	aux1.y = idRectSprite.y;
	aux1.w = idRectSprite.w;
	aux1.h = idRectSprite.h;

	SDL_Rect aux2;
	aux2.x = idRectPos.x;
	aux2.y = idRectPos.y;
	aux2.w = idRectPos.w;
	aux2.h = idRectPos.h;

	SDL_RenderCopy(m_renderer, m_textureData[id], &aux1, &aux2);
}

void Renderer::PushRotatedSprite(const std::string & id, const std::string& idRectSprite, const std::string& idRectPos ,float angle){
	SDL_Point center = { m_rects[idRectPos]->w / 2, m_rects[idRectPos]->h / 2 };
	SDL_RenderCopyEx(m_renderer, m_textureData[id], m_rects[idRectSprite], m_rects[idRectPos], angle, &center, SDL_FLIP_NONE);
}

void Renderer::SetRenderDrawColor(int r, int g, int b)
{
	SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
}

void Renderer::SetRenderDrawColor(const Color &c)
{
	SDL_SetRenderDrawColor(m_renderer, c.r, c.g, c.b, 255);
}

Renderer* Renderer::renderer = nullptr;