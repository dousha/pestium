#ifndef _ROOM_H_
#define _ROOM_H_

#include "types.h"

extern bool room_init();
extern room_t* room_get(const char*);
extern void room_finalize();

#endif
