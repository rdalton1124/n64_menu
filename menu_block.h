#ifndef MENU_BLOCK_H
#define MENU_BLOCK_H



#include "libdragon.h" 

typedef unsigned char byte; 
typedef struct 
{
	bool wrap; 	

	unsigned x; 
	unsigned y; 
	unsigned width; 
	unsigned height; 
	unsigned x_gap; 
	unsigned y_gap; 
	unsigned x_min; 
	unsigned x_max; 
	unsigned y_min; 
	unsigned y_max; 

	byte trans; 
	byte red; 
	byte green; 
	byte blue; 
} menu_block; 

void menu_block_display(menu_block*, display_context_t*);
void menu_block_init(menu_block*);

void menu_block_set_color(menu_block*, byte, byte, byte);
void menu_block_set_trans(menu_block*, byte); 
void menu_block_set_bounds(menu_block*, unsigned, unsigned, unsigned, unsigned);void menu_block_set_bound_behavior(menu_block*, bool);
 
void menu_block_move_left(menu_block*); 
void menu_block_move_right(menu_block*); 
void menu_block_move_up(menu_block*); 
void menu_block_move_down(menu_block*);

void menu_block_set_size(menu_block*, unsigned, unsigned); 
void menu_block_set_loc(menu_block*, unsigned, unsigned); 
void menu_block_set_gaps(menu_block*, unsigned, unsigned);

#endif 
