CXX = /usr/bin/g++
FLAGS = -g -Wall -W -pedantic-errors -std=c++11

OBJECTS = driver.o

.SUFFIXES: .cpp

.cpp.o: $< 
	${CXX} -c ${FLAGS} $< -o $@

default: all

all: driver

driver: ${OBJECTS}
	${CXX} ${FLAGS} ${OBJECTS} -o $@

clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1

driver.o: 	driver.cpp \
	norm.h \
	norm.hpp \
	polynomial_fnct.h \
	polynomial_fnct.hpp \
	term.h \
	term.hpp