#include "libs.h" 
#include <stdlib.h>
#include <SDL2/SDL.h> 
#include <math.h>
#include <time.h> 
#include <stdbool.h> 
#define WIDHT 800 
#define HEIGHT 600

void setUpsnake(struct Snake *snake) {
	snake->x = WIDHT / 2; 
	snake->y = HEIGHT / 2;
	snake->speed = 10; 
	snake->width = 50; 	
	snake->height = 50;
	snake->lenght = 1; 
	snake->node_t = malloc(snake->lenght * sizeof(struct node)); 
	

	for (int i = 0; i < snake->lenght; i++)
	{
		snake->node_t[i].x = snake->x; 
		snake->node_t[i].y = snake->y + (i * snake->height); 
	}
} 

void movement(struct Snake *snake, int directionx, int directiony) {
	snake->x += directionx * snake->speed; 	
	snake->y += directiony * snake->speed;
	
	for (int i = snake->lenght - 1; i > 0; --i) {
		snake->node_t[i] = snake->node_t[i - 1]; 
	} 
	snake->node_t[0].x = snake->x; 
	snake->node_t[0].y = snake->y; 
}
void freenode(struct Snake* snake) {
	free(snake->node_t);
}

void setUpdatesnake(struct Snake *snake, SDL_Renderer* renderer) {
	SDL_Rect body = {snake->x, snake->y, snake->width, snake->height}; 		
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);	
	SDL_RenderDrawRect(renderer, &body);
	SDL_RenderFillRect(renderer, &body);		
	for (int i = 0; i < snake->lenght - 1; i++) {		
		SDL_Rect newtails = {snake->node_t[i].x, snake->node_t[i].y,snake->width, snake->height}; 			
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);		
		SDL_RenderFillRect(renderer, &newtails);		
		SDL_RenderDrawRect(renderer, &newtails);
	}
}
void randomFood(struct Food* food) {
	srand(time(0)); 
	int ramdomposx = (rand() % 450); 
	int ramdomposy = (rand() % 450); 
	food->x = ramdomposx; 
	food->y = ramdomposy; 
}
void setUpfood(struct Food *food, SDL_Renderer* renderer) {
	SDL_Rect foods = {food->x, food->y, 50, 50}; 
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);		
	SDL_RenderFillRect(renderer, &foods);
}

bool collission_wall(struct Snake *snake) { 
	if (snake->x < 0 || snake->width > WIDHT) {	
		return 1; 	
	}	
	if (snake->y < 0 || snake->height > HEIGHT) {	
		return 1; 	
	}	
	return 0;  
}
bool collission_food(struct Snake *snake, struct Food* food) {
	return (snake->x < food->x + 50 && 
		snake->x + snake->width > food->x &&
		snake->y < food->y + 50	&&
		snake->y + snake->height > food->y); 	
};
