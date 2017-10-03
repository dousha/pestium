#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include "types.h"

extern bool connection_start(uint16_t port);
extern void connection_finalize();

#endif
