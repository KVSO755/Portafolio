CC = gcc
BIN_DIR = ./build
CFLAGS = Wall -g



all:
	$(CC) $(FLAGS) -o $(BIN_DIR)/main main.c