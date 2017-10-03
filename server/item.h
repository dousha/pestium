#ifndef _ITEM_H_
#define _ITEM_H_

#include "types.h"

extern bool item_init();
extern const item_t* item_get(const char*);
extern void item_finalize();

#endif

