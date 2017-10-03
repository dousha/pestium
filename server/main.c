/// main.c
/// Entry of server

#include <stdio.h>
#include <stdlib.h>

#include "texture.h"
#include "item.h"
#include "room.h"
#include "map.h"
#include "logger.h"
#include "connection.h"

int main(int argc, char** argv){
	say("main", "Starting server");
	if(!(texture_init()
	&& item_init()
	&& room_init()
	&& map_init())){
		warn("main", "Due to error occurred above, exiting.");
		exit(-1);
	}
	say("main", "Starting connection");
	connection_start(25500);
	say("main", "Stopping server.");
	map_finalize();
	room_finalize();
	item_finalize();
	texture_finalize();
	say("main", "Server closed.");
	return 0;
}
