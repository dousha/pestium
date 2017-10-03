#include <stdio.h>

#include "room.h"

bool room_init(){
	// room descriptor is not trivial compared to item desc.
	char buf[128];
	// first line:
	// $name $width $height
	//  in which $width <= 80 && $height <= 24
	// lines below:
	//  DIRECTION texture_name COORDINATE
	//   DIRECTION ::= hor
	//				|  ver
	//				|  diag
	//   COORDINATE ::= $x $y $n
	// and
	// portal $portal_name $x $y
	// finally
	// ---
	// as a separator

	return true;
}

room_t* room_get(const char* name){

}

void room_finalize(){

}
