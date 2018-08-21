GOP: main.o Card.o Deck.o Game.o Player.o Square.o Question.o
	g++ -o GOP main.o Card.o Deck.o Game.o Player.o Square.o Question.o
main.o: main.cpp
	g++ -c main.cpp
Card.o: src/card/Card.cpp
	g++ -c src/card/Card.cpp
Deck.o: src/deck/Deck.cpp
	g++ -c src/deck/Deck.cpp
Game.o: src/game/Game.cpp
	g++ -c src/game/Game.cpp
Player.o: src/player/Player.cpp
	g++ -c src/player/Player.cpp
Square.o: src/square/Square.cpp
	g++ -c src/square/Square.cpp
Question.o: src/question/Question.cpp
	g++ -c src/question/Question.cpp
clean:
	rm -f *.o GOP
