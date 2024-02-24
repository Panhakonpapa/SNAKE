#include <stdio.h>
#include "game_lib/" 
#include <stdlib.h>
#include <stdbool.h> 
#include <SDL2/SDL.h>
#define WIDTH 800
#define HEIGHT 600
int main() {
	SDL_Window* window; 
	SDL_Renderer* renderer; 
	window = SDL_CreateShapedWindow(
			NULL, 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED,
		WIDTH, 
		HEIGHT, 
		0
		); 
	renderer = SDL_CreateRenderer(window, -1, 0); 
	
	SDL_Event event; 
	int x = WIDTH / 2; 	
	int y = HEIGHT / 2;
	int velosity = 10; 
	while (true) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return -1; 
			}
		}		
		
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	
	SDL_RenderClear(renderer);			
	x += velosity;
	y += velosity;	
	if (x <= 0 || x + 50 >= WIDTH) {
	      velosity = -velosity; 	
	}
		
	if (y <= 0 || y + 50 >= HEIGHT) {
		velosity = -velosity; 	
	}
	SDL_Rect pug2 = {x, y, 50, 50}; 		
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);		
	SDL_RenderFillRect(renderer, &pug2);
	

	SDL_RenderPresent(renderer);	
	SDL_Delay(16); 	
	}

	return 0; 
}
