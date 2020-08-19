CC = gcc
CFLAGS = #-Wall -Werror -Wextra -pedantic
OBJDIR = obj
SRCDIR = .
SRC := $(shell find $(SRCDIR) -name "*.c")
OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
HEADERS := headers

$(OBJDIR)/%.o: %.c
	@mkdir -p '$(@D)'
	$(CC) -c -ggdb3 -I $(HEADERS) $(CFLAGS) $< -o $@

APP = hsh

all: $(APP)

$(APP): $(OBJ)
	$(CC) $^ -ggdb3 $(CFLAGS) -o $(APP)

%.o: %.c
	@$(CC) -c -ggdb3 $(CFLAGS) $< -o $@

clean:
	find . -name *.o -delete
	rm -f $(APP)

style:
	@betty $(shell find . -name "*.c")
	@betty $(shell find . -name "*.h")

build: clean
	@docker build --tag hsh:latest .

run: build
	@docker run --rm -it hsh:latest /bin/bash

test: build
	@printf "\n1 - case\n"
	@docker run --rm -it hsh:latest bash -c "./tests/checker.bash ./hsh ./tests/case.bash"