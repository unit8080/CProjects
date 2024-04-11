
CC = gcc
CFLAGS = -g #-Werror

CFILES = main.c \
	 quest81.c \
	 static_scope_test.c \
	 ptr_check.c \
	 string_print.c \
	 var_print.c \
	 #string.c \

OUT_EXE = out_executable

build: $(CFILES)
	$(CC) $(CFLAGS) -o $(OUT_EXE) $(CFILES)


clean:
	rm -f *.o core out_executable a.out *.i *.s


rebuild: clean build

