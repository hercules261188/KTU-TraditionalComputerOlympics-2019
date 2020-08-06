VPATH = ./src
CXXFLAGS= -I "./include"

compile&run: Car.o Convoy.o 4.Soru.o compile
	./bin/4.Soru.exe

Car.o:Car.cpp
	g++ -c $(CXXFLAGS) $< -o ./obj/Car.o

Convoy.o:Convoy.cpp
	g++ -c $(CXXFLAGS) $< -o ./obj/Convoy.o

4.Soru.o:
	g++ -c $(CXXFLAGS) ./4.Soru.cpp -o ./obj/4.Soru.o
	
compile:
	g++ ./obj/Car.o ./obj/Convoy.o ./obj/4.Soru.o -o ./bin/4.Soru.exe 