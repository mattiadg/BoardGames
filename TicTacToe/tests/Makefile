CC=g++ --std=c++11
TARGET=tests.exe
OBJS="$(TARGET) main.o TicTacToeBoardDescriptor.o"
SRCS=main.cpp TicTacToeBoardDescriptorTest.cpp ../backend/TicTacToeBoardDescriptor.cpp

test: $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)

clean:
	rm -f $(OBJS)
	rm */*.gch