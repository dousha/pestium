/// main.c
/// Entry of server

#include <stdio.h>
#include "texture.h"
#include "item.h"

int main(int argc, char** argv){
	texture_init();
	item_init();
	const item_t* i1 = item_get("mana");
	printf("%s: %s|%d %d", i1->disp_name, i1->description, i1->mod1, i1->val1);
	item_finalize();
	texture_finalize();
	return 0;
}
