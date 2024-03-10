#ifndef LIBS_H 
#define LIBS_H
#include <stdlib.h> 
#include <SDL2/SDL.h>
#include <stdbool.h>

struct node {
	int x; 
	int y; 
};

struct Snake {
	int x;  
	int y;
	int width; 
	int height; 
	int speed; 
	int lenght;
	struct node *node_t;	
};
struct Food {
	int x; 
	int y; 
}; 

void setUpsnake(struct Snake *snake);
void setUpfood(struct Food *food, SDL_Renderer* renderer); 
void setUpdatesnake(struct Snake *snake, SDL_Renderer* renderer); 
void movement(struct Snake *snake, int snakeX, int snakeY); 
bool collission_food(struct Snake *snake, struct Food* food);
bool collission_wall(struct Snake *snake);
void death_snake(struct Snake *snake); 
void randomFood(struct Food* food); 
void freenode(struct Snake* snake);
#endif  


