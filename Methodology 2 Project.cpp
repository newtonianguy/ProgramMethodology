#include <iostream>
#include "Customer.h"
#include "Bank.h"
#include <queue>
#include <stdio.h>
#include <stdlib.h>     
#include <time.h>
using namespace std;


int main(){
	srand(time(NULL));
	//Makes the bank
	Bank floor;
	//Makes the line in which customers will wait
	queue<Customer> line;
	//Asks user for number of Tellers to hire
	cout << "How many Tellers are there?\n";
	int a; cin >> a;
	int counter[a];
	for(int n=0; n<a ;n++){
		counter[n]=0;
	}
	//makes an array for tasks. Each entry is a different task corresponding to a different Teller
	int tasks[a];
	//Hires tellers 
	for(int b=0; b<a ; b++){
		floor.hireTellers();
	}
	//Asks the user what the entry rate of customers are
	cout << "How many Customers are there per minute?\nHow many Customers will come in?\n";
	int c,d; cin >> c; cin >> d;
	//Simulates a 9am to 5pm work day. Each iteration of loop is one minute. Creates c amount of customers every d minutes as specified by user prior to loop.
	//Assigns Customers to a teller if one is available. If one is not, places customer in queue until one is available.
	//Removes customer from assigned teller once teller has used appropriate amount of time to complete customer specific task. Tasks are assigned to customers randomly,
	//and take different amounts of time to execute. Check Bank class file to see different tasks and their time duration. 
	int z=0;
	for(int e=0; e<480; e++){
		//Creates c customers every  minute and gives them random task
		if(z<d){
			for(int f=0; f<c ; f++){
				int g=rand()%4;
				//Adds Customer to queue. It takes in the current time and task for customer and sets these equal to the objects private data
				Customer h;
				z++;
				h.setArrival(e);
				h.setTask(g);
				line.push(h);
			}
		}
		
		//Checks to see if a Teller is available then assigns one if there is. Also has Teller work on task if he was already assigned a customer. 
		//And checks to make sure their is no one in line.
		for(int i=0; i<a ;i++){
			if( floor.checkTellers(i) && !line.empty()==1 ){
				tasks[i]=line.front().getTask();
				floor.changeStatus(false,i);
				//Subtracts time of departure by the customers arrival to find their wait time.
				//Then removes customer from the line, and deletes the Customer object.
				floor.addWaitTime( (float)e - (float)line.front().getArrival() );
				if(!line.empty()==1){
					line.pop();
				}
				floor.doTask( tasks[i] , counter[i] , i );
			}
			else if(!line.empty()==0 && floor.checkTellers(i)==true){
				continue;
			}
			else{
				floor.doTask( tasks[i] , counter[i] , i );
			}
		}
		
		
	}
	
	
	//Asks the user for what data they want to see
	int x;
	while(x!=2){
		cout << "Input a number to select an option.\n";
		cout << "1.Output Average Wait Time\n";
		cout << "2.End Program\n";
		cin >> x;
		if(x!=1 && x!=2){
			cout << "That is not an option.\n";
		}
		else if(x==1){
			cout << floor.avgWaitTime() << endl;
		}
		else if(x==2){
			cout << "Program Ended\n";
		}
	}
	
	
}
