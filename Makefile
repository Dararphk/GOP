GOP: main.o Card.o Deck.o Game.o Player.o Square.o
	g++ -o GOP main.o Card.o Deck.o Game.o Player.o Square.o
main.o: main.cpp
	g++ -c main.cpp
Card.o:
	g++ -c src/card/Card.cpp
Deck.o:
	g++ -c src/deck/Deck.cpp
Game.o:
	g++ -c src/game/Game.cpp
Player.o:
	g++ -c src/player/Player.cpp
Square.o:
	g++ -c src/square/Square.cpp
clean:
	rm -f *.o GOP
