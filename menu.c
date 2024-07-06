#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <stdbool.h>


#include "menu_block.h" 
//test comment
typedef struct 
{
	unsigned max_text_length; 
	unsigned num_text_items;  
	char* text; 

} menu; 



void menu_set_item(menu* mnu, unsigned index, char* txt, unsigned text_length) 
{
	assert(index < mnu->num_text_items); 
	assert(text_length < mnu->max_text_length); 
}
void menu_set_text_length(menu* mnu, unsigned length)
{
	mnu->max_text_length = length; 
}
void menu_set_text_items(menu* mnu, unsigned items) 
{
	mnu->num_text_items = items; 
} 
void menu_init(menu* mnu) 
{
	mnu->text = calloc(mnu->num_text_items * mnu->max_text_length, sizeof(char)); 

}
