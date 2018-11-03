CC=g++ --std=c++11
TARGET=tests.exe
OBJS="$(TARGET) main.o TicTacToeDescriptor.o TicTacToeBoard.o TicTacToe.o TicTacToePlayer.o"
SRCS=main.cpp TicTacToeDescriptorTest.cpp TicTacToeBoardTest.cpp TicTacToeTest.cpp TicTacToePlayerTest.cpp ../backend/TicTacToeBoardDescriptor.cpp ../backend/TicTacToeBoard.cpp ../backend/TicTacToe.cpp ../engine/TicTacToePlayer.cpp

test: $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)

clean:
	rm -f $(OBJS)