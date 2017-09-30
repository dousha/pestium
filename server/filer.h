#ifndef _FILER_H_
#define _FILER_H_

#include "types.h"

extern void filer_read_tile(const char*, const tile_t*);
extern void filer_read_chunk(const char*, const chunk_t*);
extern void filer_read_room(const char*, const room_t*);
extern void filer_read_map(const char*, const map_t*);

#endif

