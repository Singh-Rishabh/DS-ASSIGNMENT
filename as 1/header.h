#ifndef HEADER_H 
#define HEADER_H


class dataName{
public:
	std::string str;
	int number;
	const bool operator<(const dataName &D) const{
		return number > D.number;
	}
};

// CLASS CAR DEFENETION

class Car{
    protected :
    	std::string color , name;
        int mileage, topSpeed , numGear ;
        bool bookStatus;
    public :
    	Car();
        Car (std::string , std::string c, int m , int t , int n);
        virtual void printc();
        void setdata(std::string , std::string c, int m , int t , int n);
        std::string getname();
        bool& getBookStatus();
        void setBookStatus( const bool a);
};

// CLASS BUS DEFENETION

class Bus : public Car{
    protected :
        int numSeats;
    public :
    	Bus();
        Bus (std::string cn,std::string c, int m , int t , int n, int ns);
        void printc();
        void setdata(std::string cn, std::string c, int m , int t , int n, int ns);
        int getSeat();
};

// CLASS TRUCK DEFENETION

class Truck : public Car{
    protected : 
        int lcINw , lcINv ;
    public :
    	Truck ();
        Truck (std::string cn, std::string c, int m , int t , int n, int lcw, int lcv);
        void printc();
        void setdata(std::string , std::string c, int m , int t , int n, int lcw, int lcv);
        int getVolume();
};


#endif
