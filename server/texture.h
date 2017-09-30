#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "types.h"

extern void texture_init();
extern const texture_t* texture_get(const char*);
extern void texture_finalize();

#endif

