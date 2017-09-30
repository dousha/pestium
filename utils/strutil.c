#include <string.h>
#include <stddef.h>
#include <stdlib.h>

size_t strqex(const char* src, char* dest, size_t offset){
	size_t left, right;
	for(left = offset; left < strlen(src); left++){
		if(src[left] == '"'){
			for(right = left + 1; right < strlen(src); right++){
				if(src[right] == '"'){
					for(size_t i = 0; i < right - left - 1; i++){
						dest[i] = src[i + left + 1];
					}
					return right + 1;
				}
			}
			return 0; // quotation mismatch
		}
	}
	return 0; // the string does not contain any quoted text
}

size_t strbex(const char* src, char* dest, size_t offset){
	size_t left = offset, right = 0;
	for(left = offset; left < strlen(src); left++){
		if(src[left] != ' ' && src[left] != '\t'){
			for(right = left; right < strlen(src); right++){
				if(src[right] == ' ' || src[right] == '\t' || src[right] == 0){
					for(size_t i = 0; i < right - left; i++){
						dest[i] = src[left + i];
					}
					return right;
				}
			}
		}
	}
	return 0; // src is filled with whitespace
}

size_t striex(const char* src, int* num, size_t offset){
	char* buf = malloc(sizeof(char) * 16);
	size_t newOffset = strbex(src, buf, offset);
	*num = atoi(buf);
	free(buf);
	return newOffset;
}
