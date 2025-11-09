Test3: Test3.cpp Car.o Option.o Model.o
		g++ Test3.cpp Car.o Option.o Model.o -o Test3

Car.o: Car.cpp Car.h Model.h Option.h
		g++ Car.cpp -c

Option.o: Option.cpp Option.h
		g++ Option.cpp -c

Model.o: Model.cpp Model.h
		g++ Model.cpp -c


clean:
	rm *.o