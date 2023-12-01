#: Compiler
CXX = g++

#: Compiler flags. -Wall enables some common warnings.
#: -std=c++11 this line sets the C++ version to C++11.
CXXFLAGS =-std=c++11 

#: This is a list of source files
SRCS = main.cpp

#: Generate a list of Object files, which are just compiled version of the source files.
#: Found by replacing the .cpp extension with the .o extension
OBJS = $(SRCS:.cpp=.o)

#: Targart is a variable that holds the executable file name
#: I have named thi executable, i.e g++ flas main.cpp -c -o executable
TARGET = executable

#: Rule to compile .cpp files into .o files
#: Where % allows us to take any file with the extension .cpp
#: $< takes the source files (%.cpp) and $@ represents the target file .o
%.o: %.cpp					
	$(CXX) $(CXXFLAGS)  -c $< -o $@

#: Rule to build the executable
#: This show how to build the final executable (TARGET) from the object files
#: by putting everything together.
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

.PHONY: clean run
run: $(TARGET)
	./$(TARGET) bin/initial_densities.txt

clean:
	rm -f $(OBJS) $(TARGET)

