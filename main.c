#include <stdio.h>
#include "game_libs/libs.h" 
#include <stdlib.h>
#include <stdbool.h> 
#include <SDL2/SDL.h>
#define WIDTH 800
#define HEIGHT 600
#define RIGHT 1 
#define LEFT -1 
#define UP -1 
#define DOWN 1 
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
	struct Snake snake;
	struct Food food; 
	setUpsnake(&snake);


	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	
	SDL_RenderClear(renderer);			
	randomFood(&food); 
	setUpfood(&food, renderer);	
	SDL_RenderPresent(renderer);	
	while (true) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return -1; 
			} 			
			const Uint8* KeyStates = SDL_GetKeyboardState(NULL);
       			if (KeyStates[SDL_SCANCODE_UP]) {
				movement(&snake, 0, UP); 
			} 	
       			if (KeyStates[SDL_SCANCODE_DOWN]) {
				
				movement(&snake, 0, DOWN); 

			}
       			if (KeyStates[SDL_SCANCODE_RIGHT]) {
				
				movement(&snake, RIGHT, 0); 

			}
       			if (KeyStates[SDL_SCANCODE_LEFT]) {
					
				movement(&snake, LEFT, 0); 
			} 
		}	

		
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	
	SDL_RenderClear(renderer);			
		
	setUpfood(&food, renderer);
	if (collission_wall(&snake) == 1) {	
		return -1;
	}			
	
	if (collission_food(&snake, &food) == true) {
		snake.lenght += 1;  	
		randomFood(&food); 	
		setUpfood(&food, renderer);	
	}	
	setUpdatesnake(&snake, renderer); 
	SDL_RenderPresent(renderer);	
	SDL_Delay(16); 	
	
	}
	freenode(&snake); 
	return 0; 
}
