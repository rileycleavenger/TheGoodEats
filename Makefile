all: src/main.cpp
	gcc -g -Wall -o TheGoodEats src/main.cpp src/Restaurant.cpp src/CSVReader.cpp

clean:
	$(RM) TheGoodEats