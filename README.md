# N64 Menus

## Purpose 
	- To create an easy way to implement game menus on the Nintendo 64 using the libdragon engine. 
	- 


## Menu Block 
### Purpose 
	- 
### Variables
	- x, y: The current location of the block. Specifically, of the top-left corner. 
	- width, height: The width and height of the block, in pixels. 
	- x_gap, y_gap: Allows the block movement to be greater than the size of the block. If you wish for there to be a gap between menu elements, specify it here. 
	- x_min, y_min: The minimum allowed x and y positions of the top left corner (inclusive) 
	- x_max, y_max: The maximum allowed x and y positions of the top left corner (inclusive))
	- wrap: If the block has reached a boundary, will attempting to move more cause it to wrap around? If set to false, the block will just stay still. 
	
	- red, blue, green, trans: 8-bit values for the color of the block (R, G, B, a)
### byte 
	- A "custom" type representing a number between 0 and 255. Made out of an unsigned char (which is a common C practice according to my understanding).
	- Used for the RGB and transparency values.  
### Functions
#### menu_block_init
	- Purpose: To allocate the necessary memory for the menu block. 
	- Inputs: menu_block menu*: Pointer to the menu block you want to init. 
	- Return: None.
	- NOTE: This does not set any of the values. It just allocates the memory. 
#### menu_block_set_loc
	- Purpose: Set the location of the block (top-left corner). 
	- Inputs: 
		- menu_block* menu: Pointer to the menu_block you want to modify.
		- unsigned x1, y1: the new values for x and y, respectively.
	- Return: None
	- NOTE: This does not check for boundaries, so be careful. 

#### menu_block_set_size
	- Purpose: Set the Size of the block 
	- Inputs:
		- menu_block* menu: Pointer to the menu_block you want to modify.
		- unsigned w, h: The new width and the new height, respectively.
#### menu_block_set_gap
	- Purpose: Sets the x_gap and y_gap values
	- Inputs:
		- menu_block* menu: a pointer to the menu_block to modify.
		- unsigned xg, unsigned yg: The values to set x_gap and y_gap to respectively.
	- Return: None
#### menu_block_set_color
	- Purpose: Sets the color of the menu block (transparency not included)
	- Inputs: 
		- menu_block* menu: Pointer to the menu_block you want to modify.
		- byte r: Value between 0 and 255 representing how red the block is.
		- byte g: Value between 0 and 255 representing how green the block is. 
		- byte b: Value between 0 and 255 representing how blue the block is. 
	- Return: None.
	- NOTE: This is just a standard RGB color space. 
#### menu_block_set_trans
	- Purpose: Sets the transparency of the menu block. 
	- Inputs:	
		- menu_block* menu: Pointer to the menu block you want to modify.
		- byte t: Value between 0 and 255 representing the transparency. 
		- Returns: None. 
#### menu_block_set_bound_behavior
	- Purpose: To set the desired bound behavior. Bound behaviors are done when you attempt to move beyond the bound. Just reaching the bound does not enact them.  The two behaviors are 
		- Wrap: Upon reaching a max or a min, the block will teleport to the other side.
		- Nothing: Does nothing. 
	- Input: 
		- menu_block* menu: Pointer to the menu_block you want to modify.
		- bool behavior: True if you want it to wrap, False if you want it to do nothing.
	- Returns: None. 

#### menu_block_set_bounds

