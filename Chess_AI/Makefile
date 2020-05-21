CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

chess:   obj obj/main.o obj/chess_game.o obj/chessboard.o obj/field.o obj/pieces.o obj/move.o
	g++ -Wall -pedantic -std=c++0x -fsanitize=address -o chess obj/main.o obj/chess_game.o \
		obj/chessboard.o obj/field.o obj/pieces.o obj/move.o
						
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

clear:
	rm -f obj/*.o chess
