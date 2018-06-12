
objects = TOUtils.o TimeOperator.o
TOUtils: $(objects)
	g++ -o TOUtils $(objects)
TimeOperator.o: timeoperator.h
	g++ -c TimeOperator.cc
TOUtils.o: timeoperator.h
	g++ -c TOUtils.cc
clean:
	rm -rf *.o TOUtils

