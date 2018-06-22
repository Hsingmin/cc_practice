
objects = Hash.o HashDemo.o

HashDemo: $(objects)
	g++ -o HashDemo $(objects)

Hash.o: hash.h
	g++ -std=c++11 -c Hash.cc

HashDemo.o: hash.h
	g++ -std=c++11 -c HashDemo.cc

clean:
	rm -rf *.o HashDemo






