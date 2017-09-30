#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdint.h>

typedef uint8_t bool;
#define true 1
#define false 0

typedef bool (*funcHwnd)(const char*);

typedef
enum color{
	BLACK = 0,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHT_GREY,
	DARK_GREY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_MAGENTA,
	LIGHT_BROWN,
	WHITE
}
color;

typedef
struct texture{
	char name[16];
	color fg;
	color bg;
	char text;
}
texture_t;	

typedef
struct tile{
	char* name;
	texture_t* texture;
	funcHwnd onEnter;
	funcHwnd onLeave;
	funcHwnd onInteract;
}
tile_t;

typedef
struct chunk{
	char* name;
	uint8_t w;
	uint8_t h;
	tile_t* tiles;
	funcHwnd onEnter;
	funcHwnd onLeave;
}
chunk_t;

typedef
struct room{
	char* name;
	chunk_t* chunks;
}
room_t;

typedef 
struct map{
	uint32_t width;
	uint32_t height;
	room_t* rooms;
}
map_t;

typedef
enum item_type{
	TYPE_DUMMY = 0,
	TYPE_EQUIPPABLE = 1,
	TYPE_CONSUMABLE = 2
}
item_type;

typedef
enum modifier_type{
	MODI_DUMMY = 0,
	MODI_STR = 1,
	MODI_DEF = 2,
	MODI_MAGIC = 3,
	MODI_DEX = 4,
	MODI_WIS = 5,
	MODI_INT = 6,
	MODI_HP = 10,
	MODI_MP = 11,
	MODI_POS = 20,
	MODI_DIRECTION = 21,
	MODI_VISIBILITY = 22,
}
modifier_type;

typedef
struct item{
	char* name;
	char* disp_name;
	char* description;
	item_type type;
	modifier_type mod1;
	int val1;
	modifier_type mod2;
	int val2;
	modifier_type mod3;
	int val3;
	int duration;
	int cooldown;
}
item_t;

typedef
enum loot_type{
	LOOT_NONE = 0,
	LOOT_ALL,
	LOOT_ONE,
	LOOT_PARTIAL
}
loot_type;

typedef
struct inventory{
	uint16_t size;
	item_t* slots;
	item_t* equipped;
}
inventory_t;

typedef
struct mob{
	loot_type loot;
	char* name;
	texture_t* texture;
	inventory_t* inv;
}
mob_t;

typedef
struct socket{
	// TODO: complete this part
}
socket_t;

typedef
struct player{
	mob_t* entity;
	socket_t* socket;
}
player_t;

#endif

