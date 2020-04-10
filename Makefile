a: test.o
	g++ test.o
test.o: test.cpp chain.h circularlist.h
	g++ -c test.cpp
clean:
	del *.o *.exe
