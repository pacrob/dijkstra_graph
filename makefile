CXX = g++
CXXFLAGS = -std=c++0x

CLASS = dijkstra.cpp
MAIN = dijkstra_main.cpp
TEST = dijkstra_test.cpp
CLASSO = dijkstra.o
MAINO = dijkstra_main.o
TESTO = dijkstra_test.o
HEADERS = dijkstra.hpp
EXEC = dmoney
TESTX = testy

all: ${CLASSO} ${MAINO} ${HEADERS}
	${CXX} ${MAINO} ${CLASSO} ${CXXFLAGS} -o ${EXEC}

test: ${CLASSO} ${TESTO} ${HEADERS}
	${CXX} ${CLASSO} ${TESTO} ${CXXFLAGS} -o ${TESTX}

${CLASSO}: ${CLASS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${MAINO}: ${MAIN}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${TESTO}: ${TEST}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ${EXEC} ${TESTX}
