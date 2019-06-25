all: cache.o core.o paineis.o main.o
	g++ -Wall -ansi -pedantic -g -o ./bin/programa.out ./build/*.o

main.o:
	g++ -c ./source/main.cpp -I ./include -o ./build/main.o

cache.o:
	g++ -c ./source/cache.cpp -I ./include -o ./build/cache.o

core.o:
	g++ -c ./source/core.cpp -I ./include -o ./build/core.o

paineis.o:
	g++ -c ./source/paineis.cpp -I ./include -o ./build/paineis.o

clear:
	rm ./build/*.o
	rm ./bin/*.out

run:
	./bin/programa.out