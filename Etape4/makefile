Test4v2: Test4.cpp Person.o Client.o Actor.o Employee.o
			g++ Test4.cpp Person.o Client.o Actor.o Employee.o -o Test4v3

Employee.o: Employee.cpp Employee.h
			g++ Employee.cpp -c


Person.o: Person.cpp Person.h
			g++ Person.cpp -c

Actor.o: Actor.cpp Actor.h
			g++ Actor.cpp -c

Client.o: Client.cpp Client.h
			g++ Client.cpp -c

clean:
	rm *.o
