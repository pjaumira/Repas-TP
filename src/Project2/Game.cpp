#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags){

	//intent de inicialitzacio de SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";

		//inicialita la finestra ara
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0) {
			std::cout << "window creation is succesful \n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) {
				std::cout << "renderer creation success \n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else {
				std::cout << "renderer init fail \n";
				return false;
			}
		}
		else {
			std::cout << "window init fail \n";
			return false;
		}
	}
	else {
		std::cout << "SLD init fail \n";
		return false;
	}

	std::cout << "init success \n";
	m_bRunning = true; //everything loaded without problem, let the main loop begin
	return true;
	}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean() {
	std::cout << "cleaning game \n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}