all: main 

main: main.cpp Calculator.cpp Variable.cpp
	g++ -g -std=c++11 main.cpp Calculator.cpp Variable.cpp

clean:
	$(RM) a.out
