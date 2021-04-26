#target: dependencies
#  action

FLAGS = -pedantic-errors -std=c++11
main.o: main.cpp header.h 
	g++ $(FLAGS) -c main.cpp

Func3.o: Func3.cpp header.h
	g++ $(FLAGS) -c Func3.cpp

Func1-2.o: Func1-2.cpp header.h
	g++ $(FLAGS) -c Func1-2.cpp

Func4.o: Func4.cpp header.h
	g++ $(FLAGS) -c Func4.cpp

FuncInter.o: FuncInter.cpp header.h
	g++ $(FLAGS) -c FuncInter.cpp 

combGame.o: combGame.cpp header.h
	g++ $(FLAGS) -c combGame.cpp

killerGame.o: killerGame.cpp header.h
	g++ $(FLAGS) -c killerGame.cpp

fileManage.o: fileManage.cpp header.h
	g++ $(FLAGS) -c fileManage.cpp 

game: fileManage.o killerGame.o combGame.o FuncInter.o Func4.o Func1-2.o Func3.o main.o
	g++ $(FLAGS) $^ -o game

clean:
	rm *.o game

.PHONY:	clean
