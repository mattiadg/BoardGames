CC=g++ --std=c++11
TARGET=tests.exe
OBJS="$(TARGET) main.o TicTacToeDescriptor.o TicTacToeBoard.o"
SRCS=main.cpp TicTacTacDescriptorTest.cpp TicTacToeBoardTest.cpp ../backend/TicTacToeBoardDescriptor.cpp ../backend/TicTacToeBoard.cpp

test: $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)

clean:
	rm -f $(OBJS)
	rm */*.gch