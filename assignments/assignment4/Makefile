CC = g++ -g
exe_file = assign

$(exe_file): driver.o Insect.o Bee.o Harvester.o Thrower.o Fire.o LongThrower.o ShortThrower.o Wall.o Ninja.o Bodyguard.o Player.o
	$(CC) driver.o Insect.o Bee.o Harvester.o Thrower.o Fire.o LongThrower.o ShortThrower.o Wall.o Ninja.o Bodyguard.o Player.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
Insect.o: Insect.cpp
	$(CC) -c Insect.cpp
Bee.o: Bee.cpp
	$(CC) -c Bee.cpp
Harvester.o: Harvester.cpp
	$(CC) -c Harvester.cpp
Thrower.o: Thrower.cpp
	$(CC) -c Thrower.cpp
Fire.o: Fire.cpp
	$(CC) -c Fire.cpp
LongThrower.o: LongThrower.cpp
	$(CC) -c LongThrower.cpp
ShortThrower.o: ShortThrower.cpp
	$(CC) -c ShortThrower.cpp
Wall.o: Wall.cpp
	$(CC) -c Wall.cpp
Ninja.o: Ninja.cpp
	$(CC) -c Ninja.cpp
Bodyguard.o: Bodyguard.cpp
	$(CC) -c Bodyguard.cpp
Player.o: Player.cpp
	$(CC) -c Player.cpp

clean:
	rm -f *.out *.o $(exe_file)