all:
	gcc -lncurses main.c -o rougelike

clean:
	rm rougelike
