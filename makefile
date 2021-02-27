# name project
TAG = rsa

# name compiler
CC = gcc

# source parametres
SRC  = main.cpp
SRC += menu.cpp
SRC += rsa.cpp

# flag parametres
FLAG  = -Wall
FLAG += -std=c11
FLAG += $(pkg-config --cflags --libs openssl)

# mode list
.PHONY: release debug clean

# release mode
release: build/release/$(TAG)

build/release/$(TAG): $(SRC)
	@echo "[RELEASE]"
	@mkdir -p build/
	@mkdir -p build/release/
	@$(CC) $(FLAG) $^ -o $@

# debug mode
debug: build/debug/$(TAG)

build/debug/$(TAG): $(SRC)
	@echo "[DEBUG]"
	@mkdir -p build/
	@mkdir -p build/debug/
	@$(CC) $(FLAG) -g $^ -o $@

# clean mode
clean:
	@echo "[CLEAN]"
	@rm -r build/
