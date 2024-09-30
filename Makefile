CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = tictactoe

all: $(TARGET)

$(TARGET): main.o game_engine.o board.o player.o painter.o cell.o
	$(CXX) -o $(TARGET).exe main.o game_engine.o board.o player.o painter.o cell.o

main.o:
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

game_engine.o:
	$(CXX) $(CXXFLAGS) -c game_engine.cpp -o game_engine.o

board.o:
	$(CXX) $(CXXFLAGS) -c board.cpp -o board.o

player.o:
	$(CXX) $(CXXFLAGS) -c player.cpp -o player.o

painter.o:
	$(CXX) $(CXXFLAGS) -c painter.cpp -o painter.o

cell.o:
	$(CXX) $(CXXFLAGS) -c cell.cpp -o cell.o

clean:
	rm -f *.o *.exe
