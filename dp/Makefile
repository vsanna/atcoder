P = a

gcc_options = -std=c++14 -Wall

build:
	g++ $(gcc_options) $(P).cpp -o main

# $ make run P=a
run: build
	./main

.PHONY: run build