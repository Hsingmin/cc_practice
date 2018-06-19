
objects = Variable.o VariableTest.o

VariableTest: $(objects)
	g++ -o VariableTest $(objects)

Variable.o: variable.h
	g++ -std=c++11 -c Variable.cc

VariableTest.o: variable.h
	g++ -std=c++11 -c VariableTest.cc

clean:
	rm -f *.o VariableTest



