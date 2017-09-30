#include <stdio.h>
#include <stdlib.h>

#include "logger.h"
#include "types.h"
#include "utils.h"
#include "../utils/utils.h"

static int _item_count = 0;
static item_t* _item_pool = NULL;

static void item_new(item_t* item){
	item->name = malloc(sizeof(char) * 16);
	item->disp_name = malloc(sizeof(char) * 32);
	item->description = malloc(sizeof(char) * 64);
}

static void item_delete(item_t* item){
	free(item->name);
	free(item->disp_name);
	free(item->description);
}

static void item_parse(item_t* item, const char* str){
	size_t nextPos = 0;
	nextPos = strbex(str, item->name, nextPos);
	nextPos = strqex(str, item->disp_name, nextPos);
	nextPos = strqex(str, item->description, nextPos);
	nextPos = striex(str, (int*) &item->mod1, nextPos);
	nextPos = striex(str, &item->val1, nextPos);
	nextPos = striex(str, (int*) &item->mod2, nextPos);
	nextPos = striex(str, &item->val2, nextPos);
	nextPos = striex(str, (int*) &item->mod3, nextPos);
	nextPos = striex(str, &item->val3, nextPos);
	nextPos = striex(str, &item->duration, nextPos);
	striex(str, &item->cooldown, nextPos);
	// any trailing characters are ignored
}

const item_t* item_get(const char* name){
	for(size_t i = 0; i < _item_count; i++){
		if(strcmp(_item_pool[i].name, name) == 0){ // TODO: could be more efficient
			return  _item_pool + i;
		}
	}
	log("Trying to get an undefined item:");
	log(name);
	return NULL;
}

void item_init(){
	FILE* fp = fopen("assets/items", "r");
	if(fp == NULL){
		log("cannot open items file!");
		return;
	}
	char buf[128];
	int count = 0;
	while(fgets(buf, 128, fp) != NULL){
		if(strlen(buf) == 0) continue;
		++count;
	}
	_item_pool = malloc(sizeof(item_t) * count);
	if(_item_pool == NULL){
		log("Cannot allocate item pool!");
		return;
	}
	_item_count = count;
	fseek(fp, 0, SEEK_SET);
	count = 0;
	while(fgets(buf, 128, fp) != NULL){
		if(strlen(buf) == 0 || buf[0] == '#') continue;
		item_new(_item_pool + count);
		item_parse(_item_pool + count, buf);
		++count;
	}
	printf("|Item> %d items loaded\n", count);
}

void item_finalize(){
	for(size_t i = 0; i < _item_count; i++){
		item_delete(_item_pool + i);
	}
	free(_item_pool);
}
