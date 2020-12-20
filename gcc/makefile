
# ------------------------------------------------
# Generic Makefile
#
# Authors: Aditi Biswas 101193708
#          Tharun Merapala 101192727
#   	   Soham Patel 101184663
#          Siddharth Ashish Upadhyaya 101207911
## Date  : 2020-12-17
# ------------------------------------------------
	   
CC = gcc

#CALLING DECLARATION FILES LOCATION 
INCLUDESNAKE = -I include

TESTBIN = cd ./test/bin;

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)
output_folder := $(shell mkdir -p out)

#TARGET TO COMPILE ALL SUDOKU GENERATOR FILES TOGETHER 
snake.o: src/snake.c
	$(CC) -g $(INCLUDESNAKE) -c ./src/snake.c -o ./build/snake.o


buildsnake: snake.o
	$(CC) -g -o bin/SNAKEGAME.exe  build/snake.o
	

#TARGET TO RUN the snake_game
runsnake: 
		cd ./out; ./SNAKEGAME.exe

#TARGET TO COMPILE AND RUN snake_game
bnrsnake: buildsnake runsnake
		

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/* output/* test/bin/* test/build/* test/output/* test/log/*
