#ifndef _MAP_H_
#define _MAP_H_

#include "types.h"

extern bool map_init();
extern map_t* map_get(const char*);
extern map_t* map_get_id(unsigned int);
extern void map_finalize();

#endif
