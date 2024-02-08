all: a
	a.out
a: test.o
	g++ test.o polynomial.o
test.o: test.cpp polynomial.o
	g++ -c test.cpp
polynomial.o: polynomial.h polynomial.cpp chain.h
	g++ -c polynomial.cpp 
gen_tags:
	ctags --languages=c++ -R *
clean:
	rm *.o *.out tags
