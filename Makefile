all: main

clean: main
	rm -fr bin/*

main:
	g++ -std=c++17 src/main.cpp -Llibs -o bin/main

