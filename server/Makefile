C_SRC=main.c item.c ../utils/strutil.c
C_DEP=logger.h types.h item.h ../utils/utils.h
C_OBJ=$(C_SRC:.c=.o)
C_FLAGS=-O2 -g -I../utils/
TARGET=pestium

default: $(C_SRC) $(C_DEP)
	make all

all: $(C_OBJ) $(C_DEP)
	gcc $(C_OBJ) $(C_FLAGS) -o $(TARGET)

clean:
	rm -rf $(C_OBJ)

%.o: %.c
	gcc -c $(C_FLAGS) $< -o $@
