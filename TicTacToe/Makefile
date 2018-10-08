CC=g++ --std=c++11
TARGET=tictactoe.exe
OBJS="$(TARGET) TicTacToeDisplay.o TicTacToe.o TicTacToeBoard.o TicTacToeBoardDescriptor.o"
SRCS=main.cpp presentation/TicTacToeDisplay.cpp backend/TicTacToe.cpp backend/TicTacToeBoard.cpp backend/TicTacToeBoardDescriptor.cpp

tictactoe: $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)

clean:
	rm -f $(OBJS)