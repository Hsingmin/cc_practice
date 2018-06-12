
objects = TFUtils.o TimeFriend.o
TFUtils: $(objects)
	g++ -o TFUtils $(objects)
TimeFriend.o: timefriend.h
	g++ -c TimeFriend.cc
TFUtils.o: timefriend.h
	g++ -c TFUtils.cc
clean:
	rm -rf *.o TFUtils

