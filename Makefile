
CXX = g++ -std=c++17 -Wall -g

all: run_test

run_test: hashing_test
	./hashing_test

headers: ItemCollection.hpp 

hashing_test: headers ItemCollection.cpp main.cpp
	${CXX} ItemCollection.cpp main.cpp -o hashing_test

clean:
	rm -f hashing_test
