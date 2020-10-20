#include<iostream>
#include<iomanip>
using namespace std;





int main(){
	
	
	string user,pass,cfpass,email,tel;
	int menu;



				cout << "================== Cinema ========================="<<endl;
				  	cout <<"1.Registration"<<endl;
	    			cout <<"2.Login"<<endl;
	    			cout <<"3.Exit"<<endl;
	    		cout << "==================================================="<<endl;
	    			cout <<"Enter :" ;
					cin >> menu;
	    
	    			
	    		switch(menu) {
	    			case 1:
	    				
	    			cout <<"Username :";
	    			cin >> user;
				
					cout <<"Password :";
	    			cin >> pass;
				
					cout <<"Confirm password :";
	    			cin >> cfpass;
				
					cout <<"E-mail :";
	    			cin >> email;
	    		
					cout <<"Tel";
	    			cin >> tel;
	    		
	    		case 2:
	    			
					cout<<"===========Login=========="<<endl;
					cout <<"Username :";
					cin >> user;
					
					cout <<"Password :";
					cin >> pass;
					cout <<"========================="<<endl;
				
				    cout << "Enter :";
				    cin >> menu2;
					//checkLogintrue
					
				 
				  
				  cout <<"1.Buy Ticket" <<endl;
				  cout <<"2.Check Promotion" <<endl;
				  cout <<"3.Transacttion History"<<endl;
				  cout <<"4.Exit"<<endl;
				  
				  	switch(menu2){
				  		int choosemov,round,seat;
				  	
							case 1: 
				  				cout <<"Enter Movie :";
				  				cin >> choosemov;
				  	
				  				cout << "Enter Round :";
				  				cin >> round;
				  				
				  				cout << "Enter Seat No:"
				  				cin >> seat;
				  				break;
				  			
				  			case 2:
				  				//promotion
				  				break;
				  			
				  			case 3:
				  				//history
				  				break;
				  			
				  			case 4:
				  				
				  				break;
				  		
				    }
					//checkloginFalse
					cout << "!!!! Invalid Username or Password !!!!"  << endl; 	
				    break;
				    
				    
					//AllStaff
					
					cout <<"1.Add a movie item"<<endl;
				    cout <<"2.Add promotion" <<endl;
				    cout <<"3.check seat details "<<endl;
				    cout <<"4.Exit"<<endl;
				    cout << "Enter :";
				    cin  >> menustaff;
				    
					switch(menustaff){
				    
						int movie,round,cinema;
					
						case 1:
				    		cout << "Enter movie :"
				    		cout >> movie;
				    		
				    		cout << "Enter Round :"
				    		cout >> round;
				    		
				    		cout << " Enter Cinema";
				    		cout >> cinema;
				    		
				    		break;
				    	
				    	case 2:
				    		
							int choice;
		 					
							cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ "<<endl;
				    		cout << "Promotion List" << endl;
				    		cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ "<<endl;
				    		cout << "1.Buy 4 get 3" << endl;
				    		cout << "2.Discount 20%" << endl;
				    		cout << "3.Discount 10%" << endl;
				    		cout << "4.Discount 5%" << endl;
				    		cout << "5.No Promotion" << endl;
				    		cout << "6.Exit" <<endl;
				    		cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ "<<endl;
				    		
				    		cout << "Enter Choice :"
							cin << choice; 
							
						
					}
				
				case 3:
					
					break; 
				}
				  
				  
					
		


	    
}
