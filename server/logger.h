/// logger.h

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <stdio.h>

#define log(msg) printf("[%s:%u]> %s\n", __FILE__, __LINE__, msg)
#define say(who, msg) printf("|%s> %s\n", who, msg)
#define warn(who, msg) printf("!%s> %s\n", who, msg)
#define debug(who, msg) printf("#%s> %s\n", who, msg)

#endif
