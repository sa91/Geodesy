distance.o : distance.hpp distance.cpp
	g++ -std=c++11 -c distance.cpp
runBasic :  distance.o  runBasic.cpp
	g++ -std=c++11 distance.o runBasic.cpp -o runBasic
run :  distance.o run.cpp 
	g++ -std=c++11 distance.o run.cpp -o run
clean :
	rm -rf run runBasic distance.o
