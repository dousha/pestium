#ifndef _MAP_H_
#define _MAP_H_

#include "types.h"

extern bool map_load();
extern map_t* map_get(const char*);
extern map_t* map_get_id(unsigned int);
extern bool map_set(const char*, const map_t*);

#endif
