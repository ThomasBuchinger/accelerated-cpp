SHELL = /bin/sh
BIN     = bin
SOURCE  = $(wildcard src/chapter*/*.cpp)
INCLUDE = include
LIBS    = lib
BUILD   = .build

OBJS    = $(SOURCE:.cpp=.o)
DEPS    = $(OBJS:.o=.d) 
CFLAGS  = -Wall -g
CC      = g++ ${CFLAGS}
LDFLAGS = 

.PHONY: clean cleandeps cleanall

all: chapter0 chapter1 chapter2 chapter3 chapter4 chapter6 chapter7 chapter10 chapter11 chapter12 chapter13 chapter14 chapter15

chapter0: hello_world
chapter1: working_with_strings
chapter2: my_framing_program framing_program
chapter3: simple_grade
chapter4: grading_program 
chapter6: example_algorithms grading_comparison
chapter7: word_count gen_sentences find_xref
chapter10: example_array example_echo example_function_pointer example_letter_grades example_memory example_predicate example_pointer
chapter11: example_vec
chapter12: example_str
chapter13:
chapter14:
chapter15:

hello_world: src/chapter0/hello_world.cpp 
	$(CC) $? -o $(BIN)/$@

working_with_strings: src/chapter1/working_with_strings.cpp
	$(CC) $? -o $(BIN)/$@

my_framing_program: src/chapter2/my_framing_program.cpp
	$(CC) $? -o $(BIN)/$@

framing_program: src/chapter2/framing_program.cpp
	$(CC) $? -o $(BIN)/$@

simple_grade: src/chapter3/grade.cpp
	$(CC) $? -o $(BIN)/$@

grading_program: src/chapter4/grade_calc.cpp src/chapter4/median.o src/chapter4/grades.o src/chapter4/student.o
	$(CC) $? -o $(BIN)/$@

example_algorithms: src/chapter6/algorithm_test.cpp src/chapter6/more_algorithms.o
	$(CC) $? -o $(BIN)/$@

grading_comparison: src/chapter6/grade_analysis.cpp src/chapter6/more_algorithms.o src/chapter6/analysis_algorithm.o src/chapter4/median.o src/chapter4/grades.o src/chapter4/student.o
	$(CC) $? -o $(BIN)/$@

word_count: src/chapter7/associative_arrays.cpp
	$(CC) $? -o $(BIN)/$@

gen_sentences: src/chapter7/generate_sentences.cpp src/chapter6/more_algorithms.o
	$(CC) $? -o $(BIN)/$@

find_xref: src/chapter7/xref.cpp src/chapter6/more_algorithms.o
	$(CC) $? -o $(BIN)/$@

example_array: src/chapter10/arrays.cpp
	$(CC) $? -o $(BIN)/$@

example_echo: src/chapter10/echo.cpp
	$(CC) $? -o $(BIN)/$@

example_function_pointer: src/chapter10/function_pointers.cpp
	$(CC) $? -o $(BIN)/$@

example_letter_grades: src/chapter10/letter_grades.cpp
	$(CC) $? -o $(BIN)/$@

example_memory: src/chapter10/memory.cpp
	$(CC) $? -o $(BIN)/$@

example_predicate: src/chapter10/predicate_functions.cpp
	$(CC) $? -o $(BIN)/$@

example_pointer: src/chapter10/simple_pointers.cpp
	$(CC) $? -o $(BIN)/$@

example_vec: src/chapter11/main.cpp src/chapter11/vec.h
	$(CC) $? -o $(BIN)/$@

example_str: src/chapter12/main.cpp src/chapter12/str.h src/chapter11/vec.h
	$(CC) $? -o $(BIN)/$@












-include $(DEPS) 

%.d: %.cpp
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) > $@

clean:
	-rm -f $(wildcard src/**/*.h.gch) 
	-rm -f $(OBJS)
	-rm -rf $(BUILD)/*
	-rm -rf $(BIN)/*
cleandeps:
	-rm -f $(DEPS)

cleanall: cleandeps clean
	
