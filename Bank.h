#ifndef BANK
#define BANK
#include <vector>
#include <iostream>
using namespace std;

class Bank{
    public:
    	Bank(){
    		cout << "Bank Constructor Called\n";
		}
		~Bank(){
    		cout << "Bank Destructor Called\n";
		}
    	//Checks to see if Teller is available. Takes Tellers number as input. Teller's number is location in vector.
    	bool checkTellers(int loc){
    		if(tellers[loc]){
    			cout << "This Teller is available\n";
    			return true;
			}
			else{
				cout << "This Teller is unavailable\n";
				return false;
			}
		}
		
		//Adds a teller to the Banks vector of Tellers
    	void hireTellers(){
    		tellers.push_back(true);
    		cout << "Teller hired\n";
		}
		//Changes status of Tellers. True means they are open and can accept customers.
		//False means they are working with someone already and cannot take someone at the moment.
		void changeStatus(bool t,int x){
			tellers[x]=t;
			cout << "Teller status changed\n";
		}
		//This function takes the task of a customer and decides how long that task will take. 
		//It will tell re-open the Teller for another customer
		// if he finishes his task. It keeps track of the tasks progress with a counter.
		//Each case of the switch statement represents a different task
		//This function takes in the task, the counter, and the Tellers number as inputs. 
		void doTask(int task,int &counter,int b){
			switch(task){
				case 0:
					//This represents DEPOSITS
					if(counter==0){
						counter=0;
						cout << "Task Finished\n";
						changeStatus(true,b);
						cout << "This Teller is now open\n";
						break;
					}
					else{
						counter=counter+1;
						cout << "Working on task\n";
						break;
					}
				case 1:
					//This represents WITHDRAWS
					if(counter==0){
						counter=0;
						cout << "Task Finished\n";
						changeStatus(true,b);
						cout << "This Teller is now open\n";
						break;
					}
					else{
						counter+=1;
						cout << "Working on task\n";
						break;
					}
				case 2:
					//This represents CHEKING YOU ACCOUNT BALANCE
					if(counter==0){
						counter=0;
						cout << "Task Finished\n";
						changeStatus(true,b);
						cout << "This Teller is now open\n";
						break;
					}
					else{
						counter+=1;
						cout << "Working on task\n";
						break;
					}
				case 3:
					//This represents MAKING A NEW ACCOUNT
					if(counter==0){
						counter=0;
						cout << "Task Finished\n";
						changeStatus(true,b);
						cout << "This Teller is now open\n";
						break;
					}
					else{
						counter+=1;
						cout << "Working on task\n";
						break;
					}
				default:
					break;
			}
		}
		//This function averages the wait times and returns that average
		float avgWaitTime(){
			float avg=0;
			for(int a=0; a<waitTime.size() ;a++){
				avg=avg+waitTime[a];
				cout << "The current sum of wait times is " << avg << endl;
			}
			avg=avg/waitTime.size();
			cout << "The average is " << avg << endl;
			return avg;
		}
		void addWaitTime(float a){
			waitTime.push_back(a);
			cout << "Customer wait time added\n";
		}
	
    private:
    	//Kepps track of tellers status
    	vector <bool> tellers;
    	//Keeps track of how long each customer waited.
    	vector<float> waitTime;
};

#endif
