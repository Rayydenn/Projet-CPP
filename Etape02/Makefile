Test2: Test2a.cpp Model.o Car.o
	g++ Test2a.cpp Model.o Car.o -o Test2av3

Model.o: Model.cpp Model.h
	g++ Model.cpp -c

Car.o: Car.cpp Car.h
	g++ Car.cpp -c

clean: 
	rm -f Car.o Model.o
