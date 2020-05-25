CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

chess:   obj obj/main.o obj/chess_game.o obj/chessboard.o obj/field.o obj/pieces.o obj/move.o obj/gui.o
	g++ -Wall -pedantic -std=c++0x -o chess obj/main.o obj/chess_game.o \
		obj/chessboard.o obj/field.o obj/pieces.o obj/move.o obj/gui.o \
		-lsfml-graphics -lsfml-window -lsfml-system
	rm -r obj
						
obj:
	mkdir obj

obj/main.o: src/main.cpp inc/chess_game.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/chess_game.o: src/chess_game.cpp inc/chess_game.hh
	g++ -c ${CXXFLAGS} -o obj/chess_game.o src/chess_game.cpp	

obj/chessboard.o: src/chessboard.cpp inc/chess_game.hh inc/field.hh
	g++ -c ${CXXFLAGS} -o obj/chessboard.o src/chessboard.cpp	

obj/field.o: src/field.cpp inc/field.hh inc/pieces.hh
	g++ -c ${CXXFLAGS} -o obj/field.o src/field.cpp	

obj/pieces.o: src/pieces.cpp inc/pieces.hh inc/move.hh
	g++ -c ${CXXFLAGS} -o obj/pieces.o src/pieces.cpp	

obj/move.o: src/move.cpp inc/move.hh
	g++ -c ${CXXFLAGS} -o obj/move.o src/move.cpp	

obj/gui.o: src/gui.cpp inc/gui.hh inc/chessboard.hh
	g++ -c ${CXXFLAGS} -o obj/gui.o src/gui.cpp

clear:
	rm -r obj
