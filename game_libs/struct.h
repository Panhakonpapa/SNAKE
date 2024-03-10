#ifndef STRUCT_H 
#define STRUCT_H 
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
#endif 
