CXX = g++
CXXFLAGS = -std=c++0x

SRCS = dijkstra_main.cpp dijkstra.cpp
OBJS = dijkstra_main.o dijkstra.o
HEADERS = dijkstra.hpp
EXEC = dmoney

all: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} ${CXXFLAGS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ${EXEC}
