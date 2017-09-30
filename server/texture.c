#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "logger.h"

static int _texture_count = 0;
static texture_t* _texture_poll = NULL;

void texture_init(){
	char buf[64];
	FILE* fp = fopen("assets/texture", "r");
	if(fp == NULL){
		log("Cannot open texture");
		return;
	}
	int i = 0;
	while(fgets(buf, 64, fp) != NULL){
		if(strlen(buf) == 0) continue;
		++i;
	}
	_texture_poll = malloc(sizeof(texture_t) * i);
	if(_texture_poll == NULL){
		log("Cannot allocate texture poll! Exiting...");
		exit(-1);
	}
	fseek(fp, 0, SEEK_SET);
	int fg, bg, count = 0;
	char txt, name[16];
	while(fgets(buf, 64, fp) != NULL){
		if(strlen(buf) == 0) continue;
		sscanf(buf, "%s %d %d %c", (char*) &name, &fg, &bg, &txt);
		strncpy(_texture_poll[count].name, name, 16);
		_texture_poll[count].fg = (color) fg;
		_texture_poll[count].bg = (color) bg;
		_texture_poll[count].text = txt;
		count++;
	}
	printf("|Texture> %d textures loaded\n", count);
	_texture_count = count;
}

const texture_t* texture_get(const char* name){
	if(_texture_poll == NULL){
		log("Call texture_init() to load texture first!");
		return NULL;
	}else{
		for(int i = 0; i < _texture_count; i++){ // TODO: could be more efficient
			if(strncmp(_texture_poll[i].name, name, 16) == 0){
				return _texture_poll + i;
			}
		}
		log("Trying to get an undefined texture:");
		log(name);
		return NULL;
	}
}

void texture_finalize(){
	free(_texture_poll);
}
