default : output 

output : main.o car.o bus.o truck.o funt.o
	g++ main.o car.o bus.o truck.o funt.o -o output
    
main.o : main.cpp 
	g++ -c main.cpp -o main.o
    
car.o : car.cpp 
	g++ -c car.cpp -o car.o
    
bus.o : bus.cpp 
	g++ -c bus.cpp -o bus.o
    
truck.o : truck.cpp 
	g++ -c truck.cpp -o truck.o
	
funt.o : funt.cpp
	g++ -c funt.cpp -o funt.o

clean : 
	rm -f output main.o car.o bus.o truck.o funt.o
