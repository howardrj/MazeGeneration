GXX=g++
CPPFLAGS=-Wall
INCS=Maze.h
LIBS=
OBJS=Maze.o

main:  main.cpp ${INCS} ${OBJS}
	${GXX} ${CPPFLAGS} -o $@ $< ${OBJS} ${LIBS}

Maze.o: Maze.cpp ${INCS}
	${GXX} ${CPPFLAGS} -c $< ${LIBS}

clean:
	rm -f ${OBJS} main
