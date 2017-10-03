#include <stddef.h>

#include "map.h"

static map_t* _map_poll = NULL;
static size_t _map_count = 0;

static void _map_new(map_t* map){

}

static void _map_delete(map_t* map){

}

bool map_init(){
	// map descriptor is much simpler than room descriptor
	// $map_name "$map_disp_name"
	// $room.$portal CONN_TYPE [@$map].$room.$portal
	// CONN_TYPE ::= - # bidirectional
	// 				| > # single-way

	return true;
}

map_t* map_get(const char* name){
	return NULL;
}

map_t* map_get_id(unsigned int id){
	return NULL;
}

void map_finalize(){

}
