main: main.o Card.o Deck.o Dice.o Game.o Player.o
	g++ -o main main.o Card.o Deck.o Dice.o Game.o Player.o
main.o: main.cpp
	g++ -c main.cpp
Card.o:
	g++ -c src/card/Card.cpp
Deck.o:
	g++ -c src/deck/Deck.cpp
Dice.o:
	g++ -c src/dice/Dice.cpp
Game.o:
	g++ -c src/game/Game.cpp
Player.o:
	g++ -c src/player/Player.cpp
clean:
	rm -f *.o main
