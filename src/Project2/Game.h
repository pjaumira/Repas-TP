#pragma once
#ifndef _Game_
#define _Game_

#include <SDL.h>

class Game {
public:
	Game() {}
	~Game() {}

	//La variable de funcionament a true
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void handleEvents() {}
	void update() {}
	void render() {}
	void clean() {}

	bool running() { return m_bRunning; }

	//accedir a la variable privada
private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
};

#endif //defined (_Game_)