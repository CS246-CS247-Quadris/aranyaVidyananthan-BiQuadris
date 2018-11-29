CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -g
EXEC = biQuadris
OBJECTS = main.o biquadris.o cell.o board.o level.o levelone.o levelzero.o leveltwo.o levelthree.o levelfour.o block.o iblock.o lblock.o sblock.o zblock.o tblock.o jblock.o oblock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
