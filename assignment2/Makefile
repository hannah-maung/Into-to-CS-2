CC = g++ -std=c++11
exe_file = game 

$(exe_file): classcard.o classdeck.o classhand.o classplayer.o classgame.o driver.o 
		$(CC) classcard.o classdeck.o classhand.o classplayer.o classgame.o driver.o -o $(exe_file)

classcard.o: classcard.cpp
		$(CC) -c classcard.cpp
classdeck.o: classdeck.cpp
		$(CC) -c classdeck.cpp
classhand.o: classhand.cpp
		$(CC) -c classhand.cpp
classplayer.o: classplayer.cpp
		$(CC) -c classplayer.cpp
classgame.o: classgame.cpp
		$(CC) -c classgame.cpp
driver.o: driver.cpp
		$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
