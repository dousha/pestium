cmake_minimum_required(VERSION 3.8)
project(pestium)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS "-O2 -g")
set(CMAKE_C_FLAGS_CLIENT -lcurses)

set(SERVER_SOURCE_FILES
        server/filer.h
        server/item.c
        server/item.h
        server/logger.h
        server/main.c
        server/map.c
        server/map.h
		server/room.h
		server/room.c
        server/texture.c
        server/texture.h
        server/types.h
		server/connection.c
		server/connection.h
        utils/strutil.c
        utils/utils.h
        utils/vector.c
        utils/vector.h
		utils/calcutil.c
		utils/hook.h
		utils/hook.c
        README.md)

set(CLIENT_SOURCE_FILES
        client/logger.h
        client/main.c
        utils/strutil.c)

add_executable(pestium-server ${SERVER_SOURCE_FILES})
set(CMAKE_BUILD_TYPE CLIENT)
add_executable(pestium ${CLIENT_SOURCE_FILES})