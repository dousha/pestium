/// logger.h

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdio.h>

#define log(msg) printf("[%s:%u]> %s\n", __FILE__, __LINE__, msg)

#endif
