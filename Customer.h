#ifndef CUSTOMER
#define CUSTOMER
#include <iostream>
#include <string>
using namespace std;

class Customer{
    public:
    	Customer(){
    		cout << "Customer Constructor Called\n";
		}
		~Customer(){
    		cout << "Customer Destructor Called\n";
		}
		//The next two functions get and set the task variable of Customer class
    	int getTask(){
    		cout << "Task returned\n";
    	    return task;
    	}
    	void setTask(int t){
    		cout << "New task set\n";
        	task=t;
    	}
    	//The next two functions get and set the arrival time variable of Customer class
    	void setArrival(int a){
    		cout << "New arrival set\n";
        	arrivalTime=a;
    	}
    	int getArrival(){
    		cout << "Arrival returned\n";
        	return arrivalTime;
    	}
    
    private:
    	int arrivalTime;
    	int task;
};

#endif
