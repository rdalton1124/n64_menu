#ifndef MENU_H
#define MENU_H 

typedef struct 
{
	unsigned num_text_items; 
	unsigned max_text_length; 
	char * text; 
}menu; 

void menu_init(menu*); 
void menu_set_text_items(menu*, unsigned);
void menu_set_text_length(menu*, unsigned); 


#endif
