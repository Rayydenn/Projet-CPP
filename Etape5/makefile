Test5: Test5.cpp Option.o OptionException.o Exception.o Car.o Model.o Employee.o Actor.o Person.o PasswordException.o
		g++ Test5.cpp Option.o OptionException.o Exception.o Car.o Model.o Employee.o Actor.o Person.o PasswordException.o -o Test5

Actor.o: Actor.cpp Actor.h
		g++ Actor.cpp -c

Person.o: Person.cpp Person.h
		g++ Person.cpp -c

Employee.o: Employee.cpp Employee.h
		g++ Employee.cpp -c

Car.o: Car.cpp Car.h
		g++ Car.cpp -c

Model.o: Model.cpp Model.h
		g++ Model.cpp -c

Option.o: Option.h Option.cpp
		g++ Option.cpp -c

PasswordException.o: PasswordException.cpp PasswordException.h
		g++ PasswordException.cpp -c

OptionException.o: OptionException.h OptionException.cpp
		g++ OptionException.cpp -c


Exception.o: Exception.cpp Exception.h
		g++ Exception.cpp -c

clean:
	rm *.o