
objects = ExceptMean.o

ExceptMean: $(objects)
	g++ -o ExceptMean $(objects)

ExceptMean.o: exceptmean.h
	g++ -c ExceptMean.cc

clean: re -rf *.o ExceptMean
