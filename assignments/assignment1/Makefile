CC = g++
exe = assignment1

$(exe): facts.o run_facts.o
	$(CC) -o $(exe) facts.o run_facts.o

facts.o: facts.cpp facts.h
	$(CC) -c facts.cpp

run_facts.o: run_facts.cpp facts.h
	$(CC) -c run_facts.cpp

clean:
	$(RM) facts.o run_facts.o .out $(exe) *.gch