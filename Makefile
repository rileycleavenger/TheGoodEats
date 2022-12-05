CC=g++

CFLAGS=-c -Wall

all: app

app: main.o CSVReader.o Restaurant.o HashSet.o HashMap.o
	$(CC) main.o CSVReader.o Restaurant.o HashSet.o HashMap.o -o app

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

CSVReader.o: src/CSVReader.cpp
	$(CC) $(CFLAGS) src/CSVReader.cpp

Restaurant.o: src/Restaurant.cpp
	$(CC) $(CFLAGS) src/Restaurant.cpp

HashSet.o: src/HashSet.cpp
	$(CC) $(CFLAGS) src/HashSet.cpp

HashMap.o: src/HashMap.cpp
	$(CC) $(CFLAGS) src/HashMap.cpp

clean:
	rm -rf *o app