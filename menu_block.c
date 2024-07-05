#include<stdlib.h>
#include<libdragon.h>

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

void menu_block_display(menu_block* menu, display_context_t* disp) 
{
	graphics_draw_box_trans(*disp, menu->x, menu->y, menu->width, menu->height, graphics_make_color(menu->red, menu->green, menu->blue, menu->trans));
}
void menu_block_set_trans(menu_block* menu, byte t) 
{
	menu->trans = t; 
}
void menu_block_set_bound_behavior(menu_block* menu, bool behavior) 
{
	menu->wrap = behavior; 
}
void menu_block_set_bounds(menu_block* menu, unsigned xMin, unsigned xMax, unsigned yMin, unsigned yMax) 
{
	menu->x_min = xMin; 
	menu->x_max = xMax; 
	menu->y_min = yMin; 
	menu->y_max = yMax; 
}
void menu_block_set_color(menu_block* menu, byte r, byte g, byte b) 
{
	menu->red = r; 
	menu->green = g; 
	menu->blue = b; 
}
void menu_block_init(menu_block* menu) 
{
	menu = (menu_block*) malloc(sizeof(menu_block));
}
void menu_block_move_left(menu_block* menu)
{
	if(menu->x - (menu->width + menu->x_gap) >= menu->x_min)
		menu->x -= menu->width + menu->x_gap; 
	else if(menu->wrap)
		menu->x = menu->x_max; 
}
void menu_block_move_right(menu_block* menu) 
{
	if(menu->x + menu->width + menu->x_gap <= menu->x_max) 	
		menu->x += menu->width + menu->x_gap; 
	else if(menu->wrap) 
		menu->x = menu->x_min;
}
void menu_block_move_up(menu_block* menu) 
{	
	if(menu->y - (menu-> height + menu->y_gap) >= menu->y_min)
		menu->y -= menu->height + menu->y_gap; 
	else if(menu->wrap)
		menu->y = menu->y_max; 
}
void menu_block_move_down(menu_block* menu)
{
	if (menu->y + menu->height + menu->y_gap <= menu->y_max)
		menu->y += menu->height + menu->y_gap; 
	else if(menu->wrap) 
		menu->y = menu->y_min; 
}
void menu_block_set_loc(menu_block* menu, unsigned x1, unsigned y1) 
{
	menu->x = x1;
	menu->y = y1;
}
void menu_block_set_gaps(menu_block* menu, unsigned xg, unsigned yg)
{
	menu->x_gap = xg; 
	menu->y_gap = yg; 
}
void menu_block_set_size(menu_block* menu, unsigned w, unsigned h) 
{
	menu->width = w; 
	menu->height = h; 
}
