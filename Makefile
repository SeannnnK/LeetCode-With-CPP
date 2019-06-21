include ./Make.defines

PROGS =	136SingleNumber\

all:	${PROGS}

136SingleNumber: 136-single-number.o
		${CXX} ${CXXFLAGS} -o $@ 136-single-number.o 

clean:
	rm -rf ${PROGS}
