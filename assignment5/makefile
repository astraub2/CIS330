CXX = g++
CXXFLAGS = -g -std=c++11

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all:  test-date test-caesar

# ROT13_OBJECTS = test-rot13cipher.o rot13cipher.o ioutils.o
# test-rot13cipher: $(ROT13_OBJECTS)
# 	$(CXX) -o $@ $(ROT13_OBJECTS)

## Define your own test-* targets here and then add them to the all: target
## For example, if you implement a Caesar cipher, define test-caesar as follows
## and then change the all: target above to "all: test-rot13cipher test-caesar"
## Do the same for test-date.
CAESAR_OBJECTS = test-caesar.o caesar.o ioutils.o
test-caesar: $(CAESAR_OBJECTS)
	$(CXX) -o $@ $(CAESAR_OBJECTS)

test-caesar.o: test-caesar.cpp
	$(CXX) $(CXXFLAGS) -c test-caesar.cpp

caesar.o: caesar.cpp caesar.hpp
	$(CXX) $(CXXFLAGS) -c caesar.cpp caesar.hpp

Date_OBJECTS = test-date.o date.o ioutils.o
test-date: $(Date_OBJECTS)
	$(CXX) -o $@ $(Date_OBJECTS)

ioutils.o: ioutils.cpp ioutils.hpp
	$(CXX) $(CXXFLAGS) -c ioutils.cpp ioutils.hpp

test-date.o: test-date.cpp
	$(CXX) $(CXXFLAGS) -c test-date.cpp

date.o: date.cpp date.hpp
	$(CXX) $(CXXFLAGS) -c date.cpp date.hpp

# Remove all objects and test- programs (TODO: add your own executables)

clean: 
	$(RM) *.o  test-date date caesar test-caesar
