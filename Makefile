project : race.o grid.o 204.o index_game.o
	cc race.o grid.o 204.o stack.o index_game.o -lncurses -lmenu -o project

race.o:	race.c stack.h stack.c
	cc -c stack.c
	cc -c race.c -lncurses -lmenu

grid.o: grid.c grid.h
	cc -c grid.c -lncurses

204.o: 204.c grid.c grid.h
	cc -c 204.c -lncurses -lmenu
	cc -c grid.c -lncurses

stack.o: stack.c stack.h
	cc -c stack.c

index_game.o: index_game.c
	cc -c index_game.c -lncurses -lmenu
