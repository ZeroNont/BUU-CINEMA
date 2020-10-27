#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<sstream>
#include<ctime>
//#include<limits>
#include <conio.h>
using namespace std;
class HISTORY{
	private:
	class node{
		public:
			string UserName;
			string MovieName;
			string Date;
			string Round;
			string TheaterID;
			string SeatID;
			string Price;
			node *link;
			node(string UserName,string MovieName,string Date,string Round,string TheaterID,string SeatID,string Price){
				this->UserName=UserName;
				this->MovieName=MovieName;
				this->Date=Date;
				this->Round=Round;
				this->TheaterID=TheaterID;
				this->SeatID=SeatID;
				this->Price = Price;
				link=NULL;
			}//funtion - node
	};//class - node
		node *head;
		node *tail;
		int count;
	public:
		
		HISTORY(){
			this->head = NULL;
			this->tail = NULL;
			this->count = 0;
		}//funtion - Member
		
		void add(string UserName,string MovieName,string Date,string Round,string TheaterID,string SeatID,string Price){
			node *Newnode = new node( UserName, MovieName, Date, Round, TheaterID, SeatID , Price);
			
		 	if(head == NULL){
		 		
				head = 	Newnode;
				tail = Newnode;
			}else{
				
				tail->link = Newnode;
				tail = Newnode;
			
			} //if-else
			count++;
		}//funtion - addMember
		
		void loadData(){
			count = 0;
			string  filein,UserName, MovieName, Date, Round, TheaterID, SeatID , Price;
			ifstream infile;
			infile.open("HISTORY.txt");
				while(getline(infile,filein)){
				//	cout << filein <<endl;
					UserName=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					MovieName=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					Date=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);
					Round=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					TheaterID=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					SeatID=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					Price=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
				//	cout << UserName << " " << MovieName <<" " <<Date <<" " <<Round <<" " <<TheaterID <<" " <<SeatID <<" " << Price<<endl;
						
				 	 	add(UserName, MovieName, Date, Round, TheaterID, SeatID , Price);

				 	 	
				 	 //	cout << "HELLO" <<endl;
						//addData		 	 	
				}//while
				
		}//funtion - LoadData	
		
		void SaveFile(){
			fstream infile;
			infile.open("HISTORY.txt",ios::trunc|ios::out);
			node *temp = head;
      		for(int i=0;i<count;i++){
				infile << temp->UserName << "," << temp->MovieName <<"," <<temp->Date 
				       <<"," <<temp->Round <<"," <<temp-> TheaterID <<"," <<temp-> SeatID <<"," << temp->Price<<endl;
				       
				       
				 //      cout << temp->UserName << "," << temp->MovieName <<"," <<temp->Date 
				  //     <<"," <<temp->Round <<"," <<temp-> TheaterID <<"," <<temp-> SeatID <<"," << temp->Price<<endl;
				temp = temp->link;
			}//loop - while
			infile.close();
		//	cin >> count;
		}//funtion - save_member
		
	
		void ShowHistory(){
			node *temp = head;
			for(int i=0;i<count;i++){
					cout << temp->UserName << " " << temp->MovieName <<" " <<temp->Date <<" " 
				     <<temp->Round <<" " <<temp-> TheaterID <<" " <<temp-> SeatID <<" " << temp->Price <<endl;	
			    temp = temp->link;
			}//for
		 	
		}

		string GetName(int index){
			node *temp = head;
			for(int i=0;i<index;i++){	
			    temp = temp->link;
			}//for
		 	return temp->UserName;
		}
		string GetMovie(int index){
			node *temp = head;
			for(int i=0;i<index;i++){	
			    temp = temp->link;
			}//for
		 	return temp->MovieName;
		}
		string GetDate(int index){
			node *temp = head;
			for(int i=0;i<index;i++){	
			    temp = temp->link;
			}//for
		 	return temp->Date;
		}
		string GetRound(int index){
			node *temp = head;
			for(int i=0;i<index;i++){	
			    temp = temp->link;
			}//for
		 	return temp->Round;
		}
		string GetThID(int index){
			node *temp = head;
			for(int i=0;i<index;i++){	
			    temp = temp->link;
			}//for
		 	return temp->TheaterID;
		}
		string GetSeatID(int index){
			node *temp = head;
			for(int i=0;i<index;i++){	
			    temp = temp->link;
			}//for
		 	return temp->SeatID;
		}
		string GetPrice(int index){
			node *temp = head;
			for(int i=0;i<index;i++){	
			    temp = temp->link;
			}//for
		 	return temp->Price;
		}
		bool CheckHistory(string name){
			node *temp = head;
			for(int i=0;i<count;i++){
				if(temp->UserName == name){
					return true;	
				}
			    temp = temp->link;
			}//for
		 	return false;
		}
		bool CheckHisName(string name,int index){
			node *temp = head;
			for(int i=0;i<index;i++){
			    temp = temp->link;
			}//for
			if(temp->UserName == name){
				return true;	
			}else{
				return false;	
			}
		}
		int GetCountHis(){
			return count;
		}
};
class Member{
	private:
	class node{
		public:
			string UserName;
			string Password;
			string Email;
			string Tel;
			node *link;
			node(string UserName,string Password,string Email,string Tel){
				this->UserName=UserName;
				this->Password=Password;
				this->Email=Email;
				this->Tel=Tel;
				link=NULL;
			}//funtion - node
	};//class - node
		node *head;
		node *tail;
		int count;
	public:
		
		Member(){
			this->head = NULL;
			this->tail = NULL;
			this->count = 0;
		}//funtion - Member
		
		void addMember(string UserName,string Password,string Email,string Tel){
			node *Newnode = new node(UserName,Password,Email,Tel);
		 	if(head == NULL){
				head = 	Newnode;
				tail = Newnode;
			}else{
				tail->link = Newnode;
				tail = Newnode;
			} //if-else
			count++;
		}//funtion - addMember
		
		void loadData(){
			string UserName,Password,Email,Tel,filein;
			ifstream infile;
			infile.open("member.txt");
				while(getline(infile,filein)){
					//cout << filein <<endl;
					UserName=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					Password=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					Email=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					Tel=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
				 	 	addMember(UserName,Password,Email,Tel);
						//addData		 	 	
				}//while
		}//funtion - LoadData	
		
		void save_member(){
			fstream infile;
			infile.open("member.txt",ios::trunc|ios::out);
			node *temp = head;
      		while(temp != NULL ){
				infile << temp->UserName << "," << temp->Password <<"," <<temp->Email <<"," <<temp-> Tel<<endl;
				temp = temp->link;
			}//loop - while
			infile.close();
		}//funtion - save_member
		
		bool CheckMember(string user,string pass){
			node *temp = head;
			for(int i=0;i<count;i++){
				if(user == temp->UserName && pass == temp->Password){
				   return true;
				}//if
			    temp = temp->link;
			}//for
		 	return false;
		}//function - login_Member
		
		bool CheckName(string user){
			node *temp = head;
			for(int i=0;i<count;i++){
				if(user == temp->UserName){
				   return true;
				}//if
			    temp = temp->link;
			}//for
		 	return false;
		}
		string GetEmail(string name){
			node *temp = head;
			for(int i=0;i<count;i++){
				if(name == temp->UserName ){
				   return temp->Email;
				}//if
			    temp = temp->link;
			}//for
			//return 
		}
		
		string GetTel(string name){
			node *temp = head;
			for(int i=0;i<count;i++){
				if(name == temp->UserName ){
				   return temp->Tel;
				}//if
			    temp = temp->link;
			}//for
			//return 
		}
		
};
class Admin{
	private:
	class node{
		public:
			string UserName;
			string Password;
			string Email;
			string Tel;
			node *link;
			node(string UserName,string Password,string Email,string Tel){
				this->UserName=UserName;
				this->Password=Password;
				this->Email=Email;
				this->Tel=Tel;
				link=NULL;
			}//funtion - node
	};//class - node
		node *head;
		node *tail;
		int count;
	public:
		Admin(){
			this->head = NULL;
			this->tail = NULL;
			this->count = 0;
		}//funtion - Admin
		
		void addAdmin(string UserName,string Password,string Email,string Tel){
			node *Newnode = new node(UserName,Password,Email,Tel);
		 	if(head == NULL){
				head = 	Newnode;
				tail = Newnode;

			}else{
				tail->link = Newnode;
				tail = Newnode;
			} //if-else
			count++;
		}//funtion - addAdmin
		
		void loadDataAdmin(){
			string UserName,Password,Email,Tel,filein;
			ifstream infile;
			infile.open("Admin.txt");
				while(getline(infile,filein)){
					UserName=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					Password=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					Email=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
					Tel=filein.substr(0,filein.find(','));
						filein.erase(0,filein.find(',')+1);	
				 	 	addAdmin(UserName,Password,Email,Tel);
						//addData		 	 	
				}//while
		}//funtion - LoadDataAdmin
			
		void save_Admin(){
			fstream infile;
			infile.open("Admin.txt",ios::trunc|ios::out);
			node *temp = head;
      		while(temp != NULL ){
				infile << temp->UserName << "," << temp->Password <<"," <<temp->Email <<"," <<temp-> Tel<<endl;
				temp = temp->link;
			}//loop - while
			infile.close();
		}//funtion - save_Admin
		
		bool CheckAdmin(string user,string pass){
			node *temp;
			temp = head;
			for(int i=0;i<count;i++){
				if(user == temp->UserName && pass == temp->Password){
				   return true;
				}//if
			    temp = temp->link;
			}//for
		 	return false;
		}//function - login_Member
		
		bool CheckName(string user){
			node *temp = head;
			for(int i=0;i<count;i++){
				if(user == temp->UserName){
				   return true;
				}//if
			    temp = temp->link;
			}//for
		 	return false;
		}
};//class - Admin


class Chair{
	public:
		string status;
		string name;
		string price;
		Chair(){
			this->status="0";
			this->name="-";	
			this->price="0";
		}	
		void add(string status,string name,string price){
			this->status=status;
			this->name=name;
			this->price=price;
		}	
		bool CheckStatus(){
			if(status == "0"){
				return true;
			}else{
				return false;
			}
		}
};
class Theater{
	public:
		string TheaterID;
		Chair chair[9];
		
		Theater(){
			TheaterID = "";
			for(int i=0;i<9;i++){
				chair[i].status = "0";
				chair[i].name = "-";
			}
		}
		int cal(){
			int sum=0;
			for(int i=0;i<3;i++){
				if(chair[i].status == "1"){
					sum = sum + 150;
				}
		}
			return sum;
		}
		bool confirmPayment(int seatID,string name){
			//cout << seatID << endl;
			//cin >> seatID;
			///show_chair();
			chair[seatID-1].name = name;
			chair[seatID-1].status = "1";
			//enum {Mon,Tue,Wed,Thur,Fri,Sat,Son};
			
			time_t now = time(0);
  			char* dt = ctime(&now);
   			tm *gmtm = gmtime(&now);
    		dt = asctime(gmtm);
   			string day,TIME;
  			TIME = dt;
   			day = TIME.substr(0,3);
   			
   			if(day == "Mon" || day == "Tue"){
   				chair[seatID-1].price = "100";
			}else if(day == "Wed"){
				chair[seatID-1].price = "80";
			}else if(day == "Thur" || day == "Fri"){
				chair[seatID-1].price = "120";
			}else if(day == "Sat" || day == "Son"){
				chair[seatID-1].price = "140";	
			}
			
			
			//cout << chair[seatID-1].name << " ID: "<< chair[seatID-1].status << endl;
			//show_chair();
		//	cin >> seatID;
			return true;
		}
		//Theaters(int index,string status,string name){
		//		chair[index].add(status,name);
		//}
		void add(int index,string status,string name,string price){
				chair[index].add(status,name,price);
		}
		void set(string TheaterID){
			this -> TheaterID = TheaterID;
		}
		void show_chair(){
			cout << "TheaterID: " << TheaterID <<endl;
			for(int i=0;i<3;i++){
				if(chair[i].status == "1"){
					cout << "X " ;
				}else{
					cout << i+1 <<" ";
				}
			}
			cout << endl;
		}
		bool CheckSeat(int seatID){
			if( seatID >= 0 && seatID <9){
				return chair[seatID].CheckStatus();
			}else{
				return false;
			}
			
		}
		string SeatData(int seatID){
			return chair[seatID].name;
		}
		
	int GetCount(){
		return 9;
	}
	void savefile(string name){
		string filename;
		fstream infile;
		filename = name +".txt";
		infile.open( filename.c_str(),ios::app);
			infile << TheaterID ;
		for(int i=0;i<9;i++){
			infile << "," << chair[i].status << "," << chair[i].name << "," << chair[i].price;
		}
			infile << endl ;
		infile.close();
	}
};

class Round{
private:
	Theater th;
	string date;
	string time;
public:
	Round(){
		this->time = "";
		this->time = "";
	}	

	void set(string date,string time,Theater th){
		this->th = th;
		this->date = date;
		this->time = time;	
	}
	bool confirmPayment(int seatID,string name){
		//cout << "date:" << date <<" " << time <<endl;
	//	th.show_chair();
		//cin >> date;
		return th.confirmPayment(seatID,name);
	}
	string GetDate(){
		return date;
	}
	string GetTime(){
		return time;
	}
	string GetID(){
		return th.TheaterID;
	}
	Theater GetTheater(){
		return th;
	}
	void show2(){
		string str;
		stringstream ss;
		cout << date <<" " <<time;
		cout << endl;
	}

	void show_chair(){
		th.show_chair();
	}
	int cal(){
		return th.cal();
	}
	void savefile(string name){
		string filename;
		fstream infile;
		filename = name +".txt";
		infile.open( filename.c_str(),ios::app);
			infile << date << "," << time << ",";
		infile.close();
		th.savefile(name);
	}

};
class movie{
private:
	class node{
		public:
			Round round;
			node *link;
			node(string date,string time,Theater th){
				round.set(date,time,th);
				link=NULL;
			}
			
	};
	
	string name;
	string np;
	string detail;
public:
	node *head;
	node *tail;
	int count;
	movie(){
		name = " ";
		detail = " ";
		this->head = NULL;
		this->tail = NULL;
		this->count = 0;
	}	
	
public:

	void add(string day,string time,Theater th){
		node *NewNode = new node(day,time,th);
		if(count == 0){
			head = NewNode;
			tail = head;
		}else{
			tail->link = NewNode;
			tail = tail->link;
		}
			count++; 
	}
	
	bool confirmPayment(string date,int time,int seatID,string name){
		node *temp = head;
		int n=1;
		for(int i=0;i<count;i++){
			if(temp->round.GetDate() == date){
				if(n == time){
					//cout << temp->round.GetDate() << "  " << temp->round.GetTime() <<endl;
					//cin >> n;
					return temp->round.confirmPayment(seatID,name);
				}
				n++;	
			}
			temp = temp -> link;	
		}	
	}
	int GetRoundTime(string date){
		node *temp = head;
		int n=1;
		for(int i=0;i<count;i++){
			if(temp->round.GetDate() == date){
				n++;	
			}
			temp = temp -> link;	
		}
		return n;
	}
	int cal(){
		int sum=0;
		node *temp = head;
		for(int i=0;i<count;i++){
			sum = sum + temp->round.cal();
			temp = temp->link;
		}
		return sum;
	}
	Theater GetTheter(string date,int time){
		node *temp = head;
		int n=1;		
/*
		for(int i=0;i<time;i++){
			if( (temp->round.GetDate() == date && temp->round.GetTime() == time) && temp->round.GetID() == id){
				return temp->round.GetTheater();
			}else{
				temp = temp->link;
			}	
		}
*/		
		for(int i=0;i<count;i++){
			if( (temp->round.GetDate() == date ) ){
				if(n == time){
						return temp->round.GetTheater();
				}
				n++;
			
			}
			temp = temp->link;
		}
		//return temp->round.GetTheater();
		cout << endl;
	}
	string GetTime(string date,int time){
		node *temp = head;
		int n=0;
		for(int i=0;i<count;i++){
			if(temp->round.GetDate() == date){
				if(n == time){
					return temp->round.GetTime();
				}
				n++;	
			}
			temp = temp -> link;
			
		}
	}
	
	string GetThID(string date,int time){
		node *temp = head;
		int n=0;
		for(int i=0;i<count;i++){
			if(temp->round.GetDate() == date){
				if(n == time){
					return temp->round.GetID();
				}
				n++;	
			}
			temp = temp -> link;
			
		}
	}
	

/*
	void add2(string day,string time,Theater th){
		int i;
		node *temp = head;
		for(i=0;i<count;i++){
			if(day == temp->day){	
					temp->time.add(time,th);
					break;
			}else{
				temp = temp->link;
			}
		}
		if(i == count){
			add(day,time,th);
		} 	
	} 
*/
	Round GetRound(int in){
		node *temp = head;
		for(int i=0;i<in;i++){
			temp = temp->link;
		}			
		return temp->round;
	}

		bool read_data(string filename){
			count = 0;
  			string filein,day,time,status,theaterID,price;
			fstream infile;
			filename = filename+".txt";
			infile.open( filename.c_str());
			if(infile.fail()){
        		return false;
       		}else{
				  	getline(infile,filein);
  				    name = filein.substr(0,filein.find(','));
  						filein.erase(0,filein.find(',')+1);
					detail = filein.substr(0,filein.find(','));
  						filein.erase(0,filein.find(',')+1);
  						
      			while(getline(infile,filein)){
      				day = filein.substr(0,filein.find(','));
  						filein.erase(0,filein.find(',')+1);
					time = filein.substr(0,filein.find(','));
  						filein.erase(0,filein.find(',')+1);
  						
  					Theater th;
  					
  					theaterID = filein.substr(0,filein.find(','));
  						filein.erase(0,filein.find(',')+1); 
  					th.set(theaterID);
  					for(int i=0;i<9;i++){						
						status = filein.substr(0,filein.find(','));
  							filein.erase(0,filein.find(',')+1);
  						name = filein.substr(0,filein.find(','));
  							filein.erase(0,filein.find(',')+1);
  						price = filein.substr(0,filein.find(','));
  							filein.erase(0,filein.find(',')+1);
  					//	cout << status << " " << name << " " << price <<endl;
  						th.add(i,status,name,price);
					}						
				add(day,time,th);				
				}
			//	cout << "Read: "<< count << endl;
				return true;	
			}

		}
		
		bool savefile(string Movie){
			string filename;
			node *temp = head;
			fstream infile;
			filename =  Movie+".txt";
		//	cout << filename << endl;
		//	cin >> filename;
			infile.open( filename.c_str(),ios::trunc|ios::out);
			infile << Movie << " " << "-"  << endl;
			infile.close();
			//cout <<"save: "<< count <<endl;
			//cin >> count;
			for(int j=0 ; j<count ; j++){
			  	//infile << temp->MFG <<" "<< temp->EXP <<endl;
			  	temp -> round.savefile(Movie);
			  	temp = temp->link;	  	
			}
			return true;
			//infile.close();	
		} 
		bool AddMovie(string date,string round,string cinemaID){
			//node *temp = head;
			/*
			for(int i;i<count;i++){
				if(temp->round.GetDate() == date){
					//if(temp->round.GetTime() )
				}
				temp = temp->link;
			} */
			//read_data()
			//cout <<"Before: " << count << endl;
			Theater Th;
			Th.set(cinemaID);
			add(date,round,Th);
			//cout <<"After: " << count << endl;
		//	cin >> count;
			return true;
		}
		
	int GetCount(){
		return count;
	}
};
class DAY{
private:
	class node{
		public:
			string movie;
			node *link;
			node(string movie){
				this->movie = movie;
				link=NULL;
			}
	};
	string date;
	node *head;
	node *tail;
	int count;
public:
	DAY(){
		this->head = NULL;
		this->tail = NULL;
		this->count = 0;
	}	

	void add(string name){
		node *NewNode = new node(name);
		if(count == 0){
			head = NewNode;
			tail = head;
		}else{
			tail->link = NewNode;
			tail = tail->link;
		}
			count++; 
	}
	void SetDate(string date){
		this->date = date;
	}
	string get_date(){
		return date;
	} 
	bool CheckMovie(string name){
		node *temp = head;
		for(int i=0;i<count;i++){
			if(temp->movie == name){
				return true;
			}else{
				temp = temp -> link;
			}
		}
		return false;
	}
	void show(){
		node *temp;
		temp = head;
		string str;
		stringstream ss;
		cout << "Date: " << date << endl; 
		for(int i=1;i<=count;i++){
			cout << temp->movie << endl;
			temp = temp->link;
		}			
		//cout << endl;
	}
	string get_name(int index){
		node *temp = head;
		for(int i=0;i<index;i++){
			temp = temp->link;
		}			
		return temp->movie;
	}
	int GetCount(){
		return count;
	}
	void savefile(){
		fstream infile;
		node *temp = head;
		infile.open("date.txt",ios::app);
		infile << date;
		for(int i=0;i<count;i++){
			infile << "," << temp->movie;
			temp = temp->link;	
		}
		infile << endl;
		infile.close();
	}
	bool CheckName(string name){
		node *temp = head;
		for(int i=0;i<count;i++){
			if(temp->movie == name){
				return true;
			}
			temp = temp->link;
		}			
		return false;
	}


};
class Calendar{
	class node{
		public:
			DAY date;
			node *link;
			node(string d){
				date.SetDate(d);
				link=NULL;
			}
			void add(string name){
				date.add(name);
			}
	};
public:
	node *head;
	node *tail;
	int count;
	Calendar(){
		count = 0;
		head = NULL;
		tail = NULL;
	}
	void add(string date){
		node *NewNode = new node(date);
		if(count == 0){
			head = NewNode;
			tail = head;
		}else{
			tail->link = NewNode;
			tail = tail->link;
		}
			count++;
		
	}
	
	DAY SearchDate(string date){
		node *temp = head;
		for(int i=0;i<count;i++){
			if( temp->date.get_date() == date){
				return temp->date;
			}
			temp = temp->link;
		}
	}
	bool CheckDate(string date){
		node *temp = head;
		for(int i=0;i<count;i++){
			if( temp->date.get_date() == date){
				return true;
			}
			temp = temp->link;
		}
		return false;
	}
	void add2(string name){
		tail->date.add(name);		
	}
	
	void show(){
		node *temp = head;
		cout << count << endl;
		for(int i=1;i<=count;i++){
			cout << "==========" << endl;
			temp->date.show();
			cout << "==========" << endl;
			temp = temp->link;
		}			
		cout << endl; 
	}
	void read_date(){
  		string filein,day,time,status,MovieName;
		fstream infile;
		int i=0;
		infile.open("date.txt");
      		while(getline(infile,filein)){
      			//cout << count << endl;
      			day = filein.substr(0,filein.find(','));
  					filein.erase(0,filein.find(',')+1);
  				//cout << "hello" << endl;
  				add(day);
				
  				while(filein.find(',') != -1){
  					MovieName = filein.substr(0,filein.find(','));
  						filein.erase(0,filein.find(',')+1);
					add2(MovieName);
				}
				MovieName = filein.substr(0,filein.find(','));
  						filein.erase(0,filein.find(',')+1);
					add2(MovieName);
 										
			}
	}
	void SaveListDate(){
		fstream infile;
		node *temp = head;
		infile.open("date.txt",ios::trunc|ios::out);
		infile.close();
      	for(int i=0;i<count;i++){
			temp->date.savefile();
			temp = temp->link;
		}//loop - for
		
	}
	int GetCount(){
		return count;
	}
	bool AddMovie(string date,string name){
		node *temp = head;
		int i;
		for(i=0;i<count;i++){
			if(temp->date.get_date() == date){
				if(temp->date.CheckName(name) != true){
					temp->date.add(name);
					break;	
				}
			}
			temp = temp->link;
		}
		if(i == count){
			add(date);
			temp = tail;
			temp->date.add(name);			
		}

	}

	
};
class ListMovie{
	class node{
		public:
			string MovieName;
			node *link;
			node(string MovieName){
				this->MovieName = MovieName;
				link=NULL;
			}
	};
public:
	movie m;
	node *head;
	node *tail;
	int count;
	
	ListMovie(){
		count = 0;
		head = NULL;
		tail = NULL;
	}

	void add(string MovieName){
		node *NewNode = new node(MovieName);
		if(count == 0){
			head = NewNode;
			tail = head;
		}else{
			tail->link = NewNode;
			tail = tail->link;
		}
			count++;
	}


	void read_ListMovie(){
  		string filein,MovieName;
		fstream infile;
		int i=0;
		infile.open("ListMovie.txt");
      		while(getline(infile,filein)){
  				add(filein);
			}
	}
	
	int GetCount(){
		return count;
	}
	string getMovieName(int index){
		node* temp=head;
		for(int i=0;i<count;i++){
			if(i==index){
			return temp->MovieName;
			}
			temp=temp->link;
		}
	}
	/*
	bool AddMovie(string d,string name,string round,string cinemaID){
		node *temp = head;
		for(int i=0;i<count;i++){
			if(temp->MovieName==name){
				m.AddMovie(d,round,cinemaID);
				bool m.savefile();
			} 
			temp=temp->link;
		}
		add(name);
		SaveListMovie();
		m.AddMovie(d,round,cinemaID);
		return m.savefile()
	}*/
	bool CheckNewMovie(string name){
		node *temp = head;
		for(int i=0;i<count;i++){
			if(temp->MovieName == name){
				//m.AddMovie(d,round,cinemaID);
				return false;
			} 
			temp=temp->link;
		}
		return true;
	}
	void SaveListMovie(){
		fstream infile;
		node *temp = head;
		infile.open("ListMovie.txt",ios::trunc|ios::out);
      	for(int i=0;i<count;i++){
			infile << temp->MovieName <<endl;
			temp = temp->link;
		}//loop - for
		infile.close();
	}//SavePromotion
};
class Promotion{
	private :
		string MoviePro[5];
		string UsePro;
		int count;
	public :
		
		Promotoion(){
			count = 0;
			UsePro = " ";
		}
		string GetUsePro(){
			return UsePro;
		}	
		string GetPro(int i){
			return MoviePro[i];	
		}
		void setPro(string Pro,int i){
			MoviePro[i]= Pro;
		}
		void ReadfilePromotion(){
			string data;
			count = 0;
			ifstream mypro;
			mypro.open("Promotion.txt");
			getline(mypro,data);
			UsePro = data;
			while(getline(mypro,data)){
				setPro(data,count);
				count++;	
			}	
		}
		void SavePromotion(){
			fstream infile;
			infile.open("Promotion.txt",ios::trunc|ios::out);
			infile << UsePro <<endl;
      		for(int i=0;i<5;i++){
				infile << MoviePro[i] <<endl;
			}//loop - for
			infile.close();
		}//SavePromotion
		
		void SetNowPromotion(int index){
			UsePro = MoviePro[index];
		}
		
		int Getsize(){
			return 5;
		}
		/*Promotion SearchPromotion(){
			return Promotion;
		}*/
};
class Payment{
	private:
		movie mo;
		Promotion pro;
	public:
		void set(movie &mo){
			this->mo = mo;
		}
		int PricePayMent(){
			pro.ReadfilePromotion();
			int price = GetPay();
			if(pro.GetUsePro() == "Discount 40 baht"){
				return price-40;
			}else if(pro.GetUsePro() == "Discount 10%"){
				return price*0.9;
			}else if(pro.GetUsePro() == "Discount 20%"){
				return price*0.8;
			}else if(pro.GetUsePro() == "Discount 50%"){
				return price*0.5;
			}else if(pro.GetUsePro() == "No Promotion"){
				return  price;
			}
		}
		int GetPay(){
			
			time_t now = time(0);
  			char* dt = ctime(&now);
   			tm *gmtm = gmtime(&now);
    		dt = asctime(gmtm);
   			string day,TIME;
  			TIME = dt;
   			day = TIME.substr(0,3);
   			int price;
   			
   			if(day == "Mon" || day == "Tue"){
   				return price = 100;
			}else if(day == "Wed"){
				return price = 80;
			}else if(day == "Thur" || day == "Fri"){
				return price = 120;
			}else if(day == "Sat" || day == "Son"){
				return price = 140;	
			}
		}
		bool confirmPayment(string date,int time,int seatID,string name){
			if(mo.confirmPayment( date,time, seatID, name)){
				mo.savefile(name);
				cout <<"HELLO"<<endl;
				string aa;
				cin >> aa;
				return true;
			}else{
				return false;
			}
		}
};
class Controler{
	private:
		Admin admin;
		Member member;
		movie m;
		Theater th;
		Calendar Cal;
		ListMovie list;
		Promotion promo;
		Payment pay;
		HISTORY his;
	public:
			string MemberTel(string name){
				return member.GetTel(name);
			}
			string MemberEmail(string name){
				return member.GetEmail(name);
			}
			void readfile(){
				//m.read_data();
				list.read_ListMovie();
				Cal.read_date();
			} 
			void readPro(){
				promo.ReadfilePromotion();
			}
			bool ReadMovie(string name){
				if(m.read_data(name)){
					return true;
				}else{
					return false;
				}
				
			//	cout << m.GetCount() <<endl;
			}
			void SaveMovie(string name){
				m.savefile(name);
			}
			
			//int cal(string name){
			int cal(){			
				//m.read_data(name);
				return m.cal();
			}
			void ReadUser(){
				member.loadData();
				admin.loadDataAdmin();				
			}
			movie GetMovie(){
				return m;
			}
			BuyMovie(){
				
			}
			DAY SearchDate(string date){
				return Cal.SearchDate(date);
			}
			Theater ShowMovieSeat(string date,int time,string name){
				//m.read_data(name);
				th = m.GetTheter(date,time);
				return th;
			}
			
			bool CheckSeat(string date,int time,string name){
				int count;
				stringstream ss;
				if(m.read_data(name)){
					ss << m.GetRoundTime(date);
					ss >> count;
					ss.clear();
					
					if( time > 0 && time < count ){
						return true; 
					}else{
						return false;	
					}
				}else{
					return false;	
				}
				
			} 
			
			Promotion GetPro(){
				promo.ReadfilePromotion();
				return promo;
			}
	
			Theater GetTh(){
				return th;
			}
			bool CheckSeat(int seatID){
				return th.CheckSeat(seatID);
			}
			bool CheckDate(string date){
				return Cal.CheckDate(date);
			}
			Member GetMember(){
				return member;
			}
			Admin GetAdmin(){
				return admin;
			}
			void RegisMember(string name,string pass,string email,string tel){
				member.addMember(name,pass,email,tel);
				member.save_member();
			}
			void RegisAdmin(string name,string pass,string email,string tel){
				admin.addAdmin(name,pass,email,tel);
				admin.save_Admin();
			}
			string SeatData(int seatID){
				return th.SeatData(seatID);
			}
			ListMovie getlistmovie(){
				return list;
			}
			Calendar getcalender(){
				return Cal;	
			}
			void SetNowPromotion(int i){
				promo.SetNowPromotion(i);
				promo.SavePromotion();
			}
			bool confirmPayment(string movie,string date,int time,int seatID,string name){
				
				 string id,r,d,pp;
				 m.confirmPayment(date,time,seatID,name);
				 m.savefile(movie);
				 stringstream ss;
				 ss << seatID;
				 ss >> id;
				 ss.clear();
				 
			//	 his.loadData();
			//	 his.ShowHistory();
			//	 cout << " \n"<< name <<" "<< movie <<" "<< date << " "<< m.GetTime(date,time-1) << " " <<m.GetThID(date,time-1) << "\n"<< endl;
				 
				 r = m.GetTime(date,time-1);
				 d = m.GetThID(date,time-1);
			//   his.add(name,movie,date,m.GetTime(date,time),m.GetThID(date,time),id,"150");
				
				 ss << pay.PricePayMent();
				 ss >> pp;
				 ss.clear();
				 his.add(name,movie,date,r,d,id,pp);
				// his.ShowHistory();
				 his.SaveFile();
				 //string a;
			//	 cout <<"HELLO"<<endl;
			//	 cin >>name;
				 return true;
				 
				//return pay.confirmPayment(date,time,seatID,name);
			}
			int PricePayMent(){
				return pay.PricePayMent();
			}
			bool AddMovie(string d,string name,string round,string cinemaID){
				if(list.CheckNewMovie(name)){
					m.read_data(name);
					Cal.AddMovie(d,name);
					Cal.SaveListDate();
					list.add(name);
					list.SaveListMovie();
					m.AddMovie( d, round, cinemaID);
					m.savefile(name);
				
				}else{
					m.read_data(name);
					Cal.AddMovie(d,name);
					Cal.SaveListDate();
					m.AddMovie( d, round, cinemaID);
					m.savefile(name);
				}
			}
			
			bool CheckHisName(string name,int index){
				return his.CheckHisName(name,index);
			}
			bool CheckHistory(string name){
				his.loadData();
				his.CheckHistory(name);
			}
			/*
			string ShowHistory(int index){
				return his.ShowHistory(index);
			}*/
			string GetName(int index){
				return his.GetName(index);
			}

			HISTORY GetHis(){
				return his;
			}
			void ReadHistory(){
				his.loadData();
			}

			int GetPay(){
				return pay.GetPay();
			}
			
};


class UI{
	private:
//		movie Movie;
//		DAY day[30];
		Controler Con;
		int count;
//		list_staff staff;
	public:
		UI(){
			Con.readfile();
		}
		bool ShowListMovie(string date){
			string name;
			int n=1;
			if(Con.CheckDate(date)){
			cout << "\n\t\t\t\t\t\t\t\t\t==================================\n" <<endl;	
				
				
				for(int i=0;i<Con.SearchDate(date).GetCount();i++){
					name = Con.SearchDate(date).get_name(i);
					cout <<"\t\t\t\t\t\t\t\t\tMovieName: "<< name <<endl;
					n = 1;			
					Con.ReadMovie(name);
					for(int j=0;j<Con.GetMovie().GetCount();j++){
						if(Con.GetMovie().GetRound(j).GetDate() == date){
							cout <<"\t\t\t\t\t\t\t\t\tRound[" << n << "] : "<< Con.GetMovie().GetRound(j).GetTime() <<" CINEMA:" << Con.GetMovie().GetRound(j).GetID() << endl;
							n++;
						}
					}
					cout << "\n\t\t\t\t\t\t\t\t\t==================================\n" <<endl;
				}//for

				return true;
			}else{
				cout << "\t\t\t\t\t\t\t\t\t=================\n" <<endl;
				cout << "\t\t\t\t\t\t\t\t\tDon't have a Movie\n" <<endl;
				cout << "\t\t\t\t\t\t\t\t\t=================\n" <<endl;
				return false;		
			}
		}
		bool ShowMovieSeat(string date,int time,string name){
		//	Con.ReadMovie(name);
			if(Con.CheckSeat(date,time,name)){
				cout << "\t\t\t\t\t\t\t\t\t" << setw(15) << left << "MovieName:"<<name << endl;
				cout << "\t\t\t\t\t\t\t\t\t" << setw(15) << left << "Date:"<< date <<endl;
				cout <<"\t\t\t\t\t\t\t\t\t" << setw(15) << left << "Round:" << Con.GetMovie().GetTime(date,time-1) << endl;
				cout <<"\t\t\t\t\t\t\t\t\t" << setw(15) << left << "Cinema:" << Con.GetMovie().GetThID(date,time-1) << endl;
				
				cout << "\n\t\t\t\t\t\t\t\t";
				for (int i=0 ;i<Con.ShowMovieSeat(date,time,name).GetCount();i++){
				//for (int i=0 ;i<9;i++){
					if(Con.GetTh().chair[i].status == "1"){
						cout << "\t[X]"<< i+1;
					}else{
						cout << "\t[ ]"<< i+1;
					}
					if( (i+1) % 3 == 0){
						cout << "\n\n\t\t\t\t\t\t\t\t";
					}
				}
				cout << "\n"<< endl;
				return true;	
			}else{
				return false;
			}
			
		}

		bool CheckStatusSeat(int seatID){
			if(Con.CheckSeat(seatID)){
				cout << "\t\t\t\t\t\t\t\t\tFinish Pls Payment" <<endl;
				return true;
			}else{
				cout << "\t\t\t\t\t\t\t\t\t!!! Pls Try Again !!!" <<endl;
				return false;
			}
		}
		
		/*
		void show_round(int Day,int index){
			string name;
			name = day[Day-1].get_name(index-1);
			cout << name << endl;
			frame.read_data(name);
			frame.show();
		}
		*/

		/*
		void showday(int time){
			day[time-1].show();
		}*/
		void CheckSeat(int seatID){
			string name;
		//	if( Con.CheckSeat(seatID) != true ){
				name = Con.SeatData(seatID);
				cout << "\t\t\t\t\t\t\t\t\t"<<"------------------------------------"<<endl;
				cout << "\t\t\t\t\t\t\t\t\tName:"<< name << endl;
				cout << "\t\t\t\t\t\t\t\t\tEmail: "<< Con.MemberEmail(name) <<endl;
				cout << "\t\t\t\t\t\t\t\t\tTel: "<< Con.MemberTel(name) <<endl;
				cout << "\t\t\t\t\t\t\t\t\t"<< "------------------------------------"<<endl;
			//	return true;
		//	}else{
				//cout << "\t!!! Pls Try Again !!!" <<endl;
			//	return false;
		//	}
		}
		void show_chair(int index){
		//	frame.show_chair(index);
		}
		void showPromotion(){
			string id;
			Con.readPro();
			cout<<"\t\t\t\t\t\t\t\t"<< " Promotion list   "<<endl;
			cout<<"\t\t\t\t\t\t\t\t"<< "------------------------------------"<<endl;
			for(int i=0;i<5;i++){
				cout <<"\t\t\t\t\t\t\t\t[" << i+1 << "]\t" << Con.GetPro().GetPro(i) << endl;
			}
			cout<<"\t\t\t\t\t\t\t\t"<< "------------------------------------"<<endl;
			cout<<"\t\t\t\t\t\t\t\tNow Promotion: " << Con.GetPro().GetUsePro() << endl;
			cout<<"\t\t\t\t\t\t\t\t"<< "------------------------------------"<<endl;
			
		}
		
		void showNowPromotion(){
			Con.readPro();
			cout <<"\t\t\t\t\t\t\t\t"<< "------------------------------------\n"<<endl;
			cout <<"\t\t\t\t\t\t\t\tNow Promotion: " << Con.GetPro().GetUsePro() << endl;
			cout <<"\n\t\t\t\t\t\t\t\t"<< "------------------------------------"<<endl;
			cout <<"\t\t\t\t\t\t\t\tTicketMovie Price"<<endl;
			cout <<"\t\t\t\t\t\t\t\tDay            " << setw(12) << right << "Price" <<endl;
			cout <<"\t\t\t\t\t\t\t\tMonday-Tuesday " << setw(10) << right <<"100" <<" Bath"<<endl;
			cout <<"\t\t\t\t\t\t\t\tWednesday      " << setw(10) << right <<"80" <<" Bath"<<endl;
			cout <<"\t\t\t\t\t\t\t\tThursday-Friday" << setw(10) << right <<"120"<<" Bath"<<endl;
			cout <<"\t\t\t\t\t\t\t\tSaturday-Sonday" << setw(10) << right <<"140"<<" Bath"<<endl;
			cout <<"\t\t\t\t\t\t\t\t"<< "------------------------------------"<<endl;
		}
		void SetNowPromotion(int id){
			Con.SetNowPromotion(id);
		}
		bool loginMember(string name,string pass){
			if(Con.GetMember().CheckMember(name,pass) ){
				return true;
			}else{
				return false;
			}
		}
		bool loginAdmin(string name,string pass){
			if(Con.GetAdmin().CheckAdmin(name,pass)){
				return true;
			}else{
				return false;
			}
		}
		bool RegisMember(string name,string pass,string email,string tel){
			//Con.GetMember().loadData();
			if(Con.GetMember().CheckName(name) != true ){
				Con.RegisMember(name,pass,email,tel);	
				return true;
			}else{
				return false;
			}
		}
		bool RegisAdmin(string name,string pass,string email,string tel){
			//Con.GetAdmin().loadDataAdmin();
			if(Con.GetAdmin().CheckName(name) != true){
				//Con.GetAdmin().addAdmin(name,pass,email,tel);
				Con.RegisAdmin(name,pass,email,tel);
				return true;	
			}else{
				return false;
			}
			
		}
		void ReadUser(){
		//	Con.GetMember().loadData();
		//	Con.GetAdmin().loadDataAdmin();
			Con.ReadUser();
		}
		void showListMovie(){
			cout << "\n\t\t\t\t\t\t\t===================== ListMovie =====================" <<endl;
			cout <<"\t\t\t\t\t\t\t" <<setw(7) <<left << "ID" << "MovieName" <<endl;
			for(int i=0 ;i<Con.getlistmovie().GetCount();i++){
			cout<< "\t\t\t\t\t\t\t["<< (i+1) <<setw(5) <<left <<"]" <<Con.getlistmovie().getMovieName(i) <<endl;
			}
			cout << "\t\t\t\t\t\t\t"<< "=====================================================" <<endl;
		}
		
		bool showSummaryAndDetail(string moviename){
			if(Con.ReadMovie(moviename) ){
			cout << "\t\t\t\t\t\t\t"<< "===================== ShowSummaryAndDetail =====================" <<endl;
			cout << "\t\t\t\t\t\t\t"<< setw(10) <<setfill(' ') <<left << "Movie       : " <<moviename << endl;
			//cout << "\t\t\t\t\t\t\t"<< setw(10) <<setfill(' ') <<left << "Showtime    : " <<setw(8) <<setfill(' ') <<Con.getcalender().head->date.get_date() <<" - " <<Con.getcalender().tail->date.get_date() << endl;
			cout << "\t\t\t\t\t\t\t"<< setw(10) <<setfill(' ') <<left << "Showtime    : " <<setw(8) <<setfill(' ') <<Con.GetMovie().head->round.GetDate() <<" - " <<Con.GetMovie().tail->round.GetDate() << endl;
			cout << "\t\t\t\t\t\t\t"<< setw(10) <<setfill(' ') <<left << "Total Chair : " <<setw(8) <<setfill(' ') <<Con.cal()/150 << endl;
		//	cout << "\t\t\t\t\t\t\t"<< setw(10) <<setfill(' ') <<left << "Unit Price  : " <<setw(8) <<setfill(' ') <<"150" << setw(5) <<setfill(' ') <<left << "Bath" <<endl;
			cout << "\t\t\t\t\t\t\t"<< setw(10) <<setfill(' ') <<left << "Net income  : " <<setw(8) <<setfill(' ') << Con.cal() << setw(5) <<setfill(' ') <<left << "Bath"<<endl;
			cout << "\t\t\t\t\t\t\t"<< "================================================================" <<endl;
				return true;
			}else{
				return false;
			}
		
		}		
		void ShowPayMent(string date,string name,int ti,int seatID){
			
			time_t now = time(0);
  			char* dt = ctime(&now);
   			tm *gmtm = gmtime(&now);
    		dt = asctime(gmtm);
   			string day,TIME;
  			TIME = dt;
   			day = TIME.substr(0,3);
   			
			cout << "\t\t\t\t\t\t\t"<< "================================================================" <<endl;
			cout << "\t\t\t\t\t\t\t\t\t" << setw(20) << left << "MovieName:"<<name << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << setw(20) << left << "Date:"<< date <<endl;
			cout <<"\t\t\t\t\t\t\t\t\t" << setw(20) << left << "Round:" << Con.GetMovie().GetTime(date,ti-1) << endl;
			cout <<"\t\t\t\t\t\t\t\t\t" << setw(20) << left << "Cinema:" << Con.GetMovie().GetThID(date,ti-1) << endl;
			cout <<"\t\t\t\t\t\t\t\t\t" << setw(20) << left << "SeatID:" << seatID << endl;
			cout << "\t\t\t\t\t\t\t"<< "================================================================" <<endl;
			cout << "\t\t\t\t\t\t\t\t\tDay: " << day << endl;
			cout <<"\t\t\t\t\t\t\t\t\t" << setw(20) << left << "TricketPrice:" << Con.GetPay() << " Bath"<< endl;
			cout <<"\t\t\t\t\t\t\t\t\t" << setw(20) << left << "Promotion:" << Con.GetPro().GetUsePro() << endl;
			cout <<"\t\t\t\t\t\t\t\t\t" << setw(20) << left << "Sum:" << Con.PricePayMent() << " Bath"<< endl;
			cout << "\t\t\t\t\t\t\t"<< "================================================================" <<endl;
		}

		bool confirmPayment(string movie,string date,int time,int seatID,string name){
			 return   Con.confirmPayment(movie,date,time, seatID, name);
				//ShowMovieSeat(date,time,movie);
				//int menu;
				//cin >> menu;
		}
		void PP(string name){
			Con.ReadMovie(name);
		//	Con.SaveMovie(name);
		}
		bool AddMovie(string d,string name,string round,string cinemaID){
			return Con.AddMovie( d, name, round, cinemaID);
		}
		void ShowHistory(string name){
			
			if(Con.CheckHistory(name)){
					    cout << "\t\t\t\t\t" 
							 << setw(15) << left << "MovieName" 
						     << setw(15) << left << "Date"
							 << setw(15) << left << "Round" 
							 << setw(15) << left << "CinemaID"
							 << setw(15) << left << "SeatID"
							 << setw(15) << left << "Price\n" << endl;	
				//cout << name <<" " << Con.GetHis().GetCountHis() << endl;
				for(int i=0;i<Con.GetHis().GetCountHis();i++){
					if(Con.CheckHisName(name,i)){
						cout << "\t\t\t\t\t" 
							 << setw(15) << left << Con.GetHis().GetMovie(i) 
						     << setw(15) << left << Con.GetHis().GetDate(i) 
							 << setw(15) << left << Con.GetHis().GetRound(i) 
							 << setw(15) << left << Con.GetHis().GetThID(i) 
							 << setw(15) << left << Con.GetHis().GetSeatID(i) 
							 << Con.GetHis().GetPrice(i) << " Bath"<< endl;	
					}
				}	
			}	
		}
		
		void ReadHistory(){
			Con.ReadHistory();
		}
		
};

bool CheckDay(string date){
		stringstream ss;
		
		time_t ttime = time(0);
        tm *local_time = localtime(&ttime);
				
    	int year,mount,day;
    //	cout << date.size() <<endl;
	//	cin >> day;
		if(date.size() == 8){
			ss << date.substr(6,2);
			ss >> year;
			ss.clear();
			
			ss << date.substr(3,2);
			ss >> mount;
			ss.clear();
			
			ss << date.substr(0,2);
			ss >> day;
			ss.clear();
		
			int SumDay,SumTemp;
			SumDay = day + (mount*31) + (year*12*31);
			SumTemp = local_time->tm_mday + ((1+local_time->tm_mon)*31) + ((local_time->tm_year-57)*12*31);
		
			if(SumDay >= SumTemp){
				return true;
			}else{
				return false;
			} 	
		}else{
			return false;
		}

}
bool CheckDate(string w){
	string d,m,y;
	int day,mount,year;
	stringstream ss;
	d=w.substr(0,w.find('/'));
 	ss<<d;
	ss>>day;
 	ss.clear();
 	w.erase(0,w.find('/')+1);
 	m=w.substr(0,w.find('/'));
 	ss<<m;
 	ss>>mount;
 	w.erase(0,w.find('/')+1);
 	y=w;
 	ss<<w;
 	ss>>year;
 	if(day>31||day<1){
 		 return false;
 	}else if(mount>12||mount<1){
  		return false;
 	}else{
 		 return true;
	 }
}
int MENU(string word,int n){
	char key[100];
	int i;
		cout << "\t\t\t\t\t\t\t\t\t" << word;
		cin >> key;
		i=atoi(key);
		if(i > 0 && i <= n){
			return i;
		}else{
			return -1;
		}
}
void LogoBuy(){
			cout<<"\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
			cout<<"\t\t\t\t"<<"                                   *                                                                       "<<endl;
			cout<<"\t\t\t\t"<<"                 *																				           "<<endl;			
			cout<<"\t\t\t\t"<<"888888b.   888     888 Y88b   d88P              88888888888 8888888 .d8888b.  888    d8P  8888888888 88888888888 "<<endl;
			cout<<"\t\t\t\t"<<"888   88b  888     888  Y88b d88P                   888       888  d88P  Y88b 888   d8P   888            888 "<<endl;    
			cout<<"\t\t\t\t"<<"888  .88P  888     888   Y88o88P                    888       888  888    888 888  d8P    888            888 "<<endl;    
			cout<<"\t\t\t\t"<<"8888888K.  888     888    Y888P                     888       888  888        888d88K     8888888        888 "<<endl;    
			cout<<"\t\t\t\t"<<"888   Y88b 888     888     888                      888       888  888        8888888b    888            888  "<<endl;   
			cout<<"\t\t\t\t"<<"888    888 888     888     888        888888        888       888  888    888 888  Y88b   888            888  "<<endl;   
			cout<<"\t\t\t\t"<<"888   d88P Y88b. .d88P     888                      888       888  Y88b  d88P 888   Y88b  888            888  "<<endl;   
			cout<<"\t\t\t\t"<<"8888888P     Y88888P       888                      888     8888888  Y8888P   888    Y88b 8888888888     888  "<<endl;   
			cout<<"\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
			cout<<"\t\t\t\t"<<"                                   *                                                                "<<endl;
}
void LogoSale(){
						cout<<"\t\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
						cout<<"\t\t\t\t\t"<<"                                   *                                                                "<<endl;
						cout<<"\t\t\t\t\t"<<"                 *																		           "<<endl;
					  	cout<<"\t\t\t\t\t"<<"888b     d888                   d8b    		                  888                   			"<<endl;           
						cout<<"\t\t\t\t\t"<<"8888b   d8888                   Y8P    		                  888                   			" <<endl;         
						cout<<"\t\t\t\t\t"<<"88888b.d88888                                                     888            "  <<endl;     
						cout<<"\t\t\t\t\t"<<"888Y88888P888  .d88b.  888  888 888  .d88b.	.d8888b   88888b. 888  .d88b.  .d8888b  		"   <<endl;
						cout<<"\t\t\t\t\t"<<"888 Y888P 888  d888""88b 888  888 888 d8P  Y8b	88K           88b 888 d8P  Y8b 88K      		"  <<endl;
						cout<<"\t\t\t\t\t"<<"888  Y8P  888 888  888 Y88  88P 888 88888888	Y88888b. .d888888 888 88888888 Y88888b. 		"  <<endl;
						cout<<"\t\t\t\t\t"<<"888       888 Y88..88P  Y8bd8P  888 Y88b     	     X88 888  888 888 Y8b.     X88				"<<endl;      
						cout<<"\t\t\t\t\t"<<"888       888  Y8888P    Y88P   888  Y8888  	 88888P'  Y888888 888  Y88888   88888P' 			"<<endl;
						cout<<"\t\t\t\t\t"<<"       *                                             *          *                        *           "<<endl;
						cout<<"\t\t\t\t\t"<<"                                   *                                                                 "<<endl;
						cout<<"\t\t\t\t\t"<<"                 *																			        "<<endl;
}
void LogoPro(){
	
}
void LogoSeat(){
						cout<<"\t\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
						cout<<"\t\t\t\t\t"<<"                                   *                                                                "<<endl;
						cout<<"\t\t\t\t\t"<<"                 *																		           "<<endl;
					  	cout<<"\t\t\t\t\t"<<"888b     d888                   d8b    		                           888                   			"<<endl;           
						cout<<"\t\t\t\t\t"<<"8888b   d8888                   Y8P    		                           888                   			" <<endl;         
						cout<<"\t\t\t\t\t"<<"88888b.d88888                                                              888            "  <<endl;     
						cout<<"\t\t\t\t\t"<<"888Y88888P888  .d88b.  888  888 888  .d88b.	.d8888b   .d88b.   8888b.  888888  		"   <<endl;
						cout<<"\t\t\t\t\t"<<"888 Y888P 888  d888""88b 888  888 888 d8P  Y8b	88K      d8P  Y8b      88b 888        		"  <<endl;
						cout<<"\t\t\t\t\t"<<"888  Y8P  888 888  888 Y88  88P 888 88888888	 Y8888b. 88888888 .d888888 888   		"  <<endl;
						cout<<"\t\t\t\t\t"<<"888       888 Y88..88P  Y8bd8P  888 Y88b     	     X88 Y8b.     888  888 Y88b. 				"<<endl;      
						cout<<"\t\t\t\t\t"<<"888       888  Y8888P    Y88P   888  Y8888  	 88888P'  Y88888   Y888888  Y888 			"<<endl;
						cout<<"\t\t\t\t\t"<<"       *                                             *          *                        *           "<<endl;
						cout<<"\t\t\t\t\t"<<"                                   *                                                                 "<<endl;
						cout<<"\t\t\t\t\t"<<"                 *																			        "<<endl;
}
void LogoBUU(){
		cout<<"\t\t\t\t"<<"o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o  o o "<<endl;					                                                                    
		cout<<"\t\t\t\t"<<"------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\t\t\t\t"<<"888888b.   888     888 888     888        .d8888b. 8888888 888b    888 8888888888 888b     d888        d8888 "<<endl;
		cout<<"\t\t\t\t"<<"888   88b  888     888 888     888       d88P  Y88b  888   8888b   888 888        8888b   d8888       d88888 "<<endl;
		cout<<"\t\t\t\t"<<"888  .88P  888     888 888     888       888    888  888   88888b  888 888        88888b.d88888      d88P888 "<<endl;
		cout<<"\t\t\t\t"<<"8888888K.  888     888 888     888       888         888   888Y88b 888 8888888    888Y88888P888     d88P 888 "<<endl;
		cout<<"\t\t\t\t"<<"888   Y88b 888     888 888     888       888         888   888 Y88b888 888        888 Y888P 888    d88P  888 "<<endl;
		cout<<"\t\t\t\t"<<"888    888 888     888 888     888       888    888  888   888  Y88888 888        888  Y8P  888   d88P   888 "<<endl;
		cout<<"\t\t\t\t"<<"888   d88P Y88b. .d88P Y88b. .d88P       Y88b  d88P  888   888   Y8888 888        888       888  d8888888888 "<<endl;
		cout<<"\t\t\t\t"<<"8888888P     Y88888P     Y88888P           Y8888P  8888888 888    Y888 8888888888 888       888 d88P     888 "<<endl;					                                                                    
		cout<<"\t\t\t\t"<<"------------------------------------------------------------------------------------------------------------"<<endl;
}
int main(){

	UI BUU;
	Calendar c;
	string MeNu;
	string TEST;
	int menu,menu2,menu3,mode,id,roundID;
	string d,name,round,ID,str;
	string CardID,MY,cinemaID;
	string user,pass,cfpass,email,tel;
	BUU.ReadUser();
	//BUU.showListMovie(); //show list move of summary purchase
	//BUU.showSummaryAndDetail("ironman");
	BUU.PP("ironman");
	
/*
	HISTORY hh;
	hh.loadData();
//	hh.ShowHistory("frame");
//	hh.SaveFile();
cout <<"HELLO: ";
	cin >>menu; */
login:
	do{
		system("CLS");
 
			LogoBUU();
			cout << "\t\t\t\t\t\t\t\t      "<< str <<endl;
			cout <<endl;
			cout <<"\t\t\t\t\t\t\t\t\t"<<"1.L O G I N _ M E M B E R"<<endl;
			cout <<"\t\t\t\t\t\t\t\t\t"<<"2.L O G I N _ A D M I N"<<endl;
			cout <<"\t\t\t\t\t\t\t\t\t"<<"3.R E G I S T E R"<<endl;
			cout <<"\t\t\t\t\t\t\t\t\t"<<"4.E X I T"<<endl;
			cout << endl;
			//cout <<"\t\t\t\t\t\t\t\t\t"<<"Enter :" ;
			//cin >> menu;
			 menu = MENU("Menu(1-4): ",4);
			
			switch(menu){
					case 4: 
				    	goto exit; //fogetdelet
				    	break;
				    	
					case 1:
					case 2:
					//	system("CLS");
					//	LogoBUU();
						cout <<endl;
	    				cout <<endl;
						cout<<"\t\t\t\t\t\t\t"<<"+____________________L O G I N_______________________+"<<endl;
						cout <<endl;
						cout <<"\t\t\t\t\t\t\t"<<"USERNAME :";
						cin >> user;
						cout <<"\t\t\t\t\t\t\t"<<"PASSWORD :";
						cin >> pass;
						cout<<"\t\t\t\t\t\t\t"<<"+____________________________________________________+"<<endl;
						if(menu == 1){
							if(BUU.loginMember(user,pass)){
								goto member;
							}else{
								str = "!! UserName/Password Incorrect !!";
							}
						}else if(menu == 2){
							if(BUU.loginAdmin(user,pass)){
								goto staff;
							}else{
								str = "!! UserName/Password Incorrect !!";
							}							
						}
						break;
					
					case 3:	
						string key;		
						int mode;
						system("CLS");
						LogoBUU();
						cout << endl;
	    				cout << endl;
	    				cout << "\t\t\t\t\t\t\t\t\t1.Member" << endl;
	    				cout << "\t\t\t\t\t\t\t\t\t2.Admin" <<endl;
	    				//cout << "\t\t\t\t\t\t\t\tEnterMode: ";
	    				//cin >> mode;
	    				mode = MENU("Menu(1-2): ",2);
	    				if(mode > 0 && mode < 3){
	    					
 	    				cout<<"\t\t\t\t\t\t\t"<<"+____________________ R E G I S T E R ______________________+"<<endl;
	    				cout <<endl;
	    				cout <<"\t\t\t\t\t\t\t"<<"USERNAME :";
	    				cin >> user;
						cout <<"\t\t\t\t\t\t\t"<<"PASSWORD :";
	    				cin >> pass;
						cout <<"\t\t\t\t\t\t\t"<<"E-MAIL :";
	    				cin >> email;
	    				cout <<"\t\t\t\t\t\t\t"<<"TEL :";
	    				cin >> tel;
						cout<<"\t\t\t\t\t\t\t"<<"+____________________________________________________+"<<endl;
						if(mode == 1){
							if ( BUU.RegisMember(user,pass,email,tel) == true ){
								str = "Register Finish";
							}else{
								str = "!! UserName Has Use !!";
							}
						}else{
							cout <<"\t\t\t\t\t\t\tEnter CodeAdmin: ";
							cin >> key;
							if(key == "FRAME"){
								if(BUU.RegisAdmin(user,pass,email,tel) == true ){
									str = "Register Finish";
								}else{
									str = "!! UserName Has Use !!";
								}	
							}else {
								str = "!! CodeAdmin Incorrect !!";
							}
						}
						
						}	//if
	    				break;
	    			

			}
	}while(menu != 4);

member: //fogetdelet
	do{
		system("CLS");
		cout<<"\n\n\n";
cout<<"\t\t\t"<<"x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x-"<<endl;
cout<<endl;		
cout<<"\t\t\t"<<"888b     d888 8888888888 888b     d888 888888b.   8888888888 8888888b.        888b     d888 8888888888 888b    888 888     888"<<endl; 
cout<<"\t\t\t"<<"8888b   d8888 888        8888b   d8888 888   88b  888        888   Y88b       8888b   d8888 888        8888b   888 888     888"<<endl;
cout<<"\t\t\t"<<"88888b.d88888 888        88888b.d88888 888  .88P  888        888    888       88888b.d88888 888        88888b  888 888     888"<<endl; 
cout<<"\t\t\t"<<"888Y88888P888 8888888    888Y88888P888 8888888K.  8888888    888   d88P       888Y88888P888 8888888    888Y88b 888 888     888"<<endl; 
cout<<"\t\t\t"<<"888 Y888P 888 888        888 Y888P 888 888   Y88b 888        8888888P         888 Y888P 888 888        888 Y88b888 888     888"<<endl; 
cout<<"\t\t\t"<<"888  Y8P  888 888        888  Y8P  888 888    888 888        888 T88b         888  Y8P  888 888        888  Y88888 888     888"<<endl; 
cout<<"\t\t\t"<<"888       888 888        888       888 888   d88P 888        888  T88b        888       888 888        888   Y8888 Y88b. .d88P"<<endl; 
cout<<"\t\t\t"<<"888       888 8888888888 888       888 8888888P   8888888888 888   T88b       888       888 8888888888 888    Y888   Y88888P "<<endl; 
cout<<endl;
cout<<"\t\t\t"<<"x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x-"<<endl;	                                                                                                                              
		
		cout << endl;
		cout <<"\t\t\t\t\t\t\t\t"<<"1.B U Y - T I C K E T" << endl;
		cout <<"\t\t\t\t\t\t\t\t"<<"2.C H E C K - P R O M O T I O N" << endl;
		cout <<"\t\t\t\t\t\t\t\t"<<"3.H I S T O R Y " << endl;
		cout <<"\t\t\t\t\t\t\t\t"<<"4.B A C K" << endl;
		cout << endl;
		//cout <<"\t\t\t\t\t\t\t\t"<< "Enter: ";
		//cin >> menu;
		menu = MENU("Menu(1-4): ",4);
	
		if(menu==1){
			
			str = " ";
			system("CLS");
			cout << endl;
			LogoBuy();
			cout << str << endl;                                                                                                      
			cout << "\t\t\t\t\t\t\t\tCheck Date: ";
			cin >> d;
			//if( d )
			if(CheckDate(d) && CheckDay(d)){
				do{						
					system("CLS");	
					LogoBuy();
					cout << "\t\t\t\t\t\t\t\t\tDate: " << d << endl;
					if( BUU.ShowListMovie(d) ){
					menu2 = MENU("1.Buy Movie , 2.BACK: ",2);
					
					if(menu2 == 1){
						cout << "\t\t\t\t\t\t\t\t\tName: ";
							cin >>name;
			//			cout <<"\t\t\t\t\t\t\t\tRound: ";
			//				cin >> roundID;
							
						roundID = MENU("Round: ",10);
						
						do{
						system("CLS");	
						LogoBuy();	
						cout << endl;
						//cout <<"\t\t\t\t\t\t\t\t\t====================" <<endl;
						if ( BUU.ShowMovieSeat(d,roundID,name) ){
							menu3 = MENU("1.BuyMovie // 2.BACK : ",2);
						
							if(menu3 == 1){								
								id = MENU("SeatID: ",10);
								
								//if(menu2 == 1){
								if(BUU.CheckStatusSeat(id-1)){
									/*
									cout << "\t\t\t\t\t\t\t\t\tCredit Card: ";
									cin >> CardID;
									cout << "\t\t\t\t\t\t\t\t\tMount/Year: ";
									cin >> MY;
									cout << "\t\t\t\t\t\t\t\t\tEmail: ";
									cin >> email;
									cout << "\t\t\t\t\t\t\t\t\tTel: ";
									cin >> tel;
									*/
									
									system("CLS");	
									LogoBuy();
									//cout << "\t\t\t\t\t\t\t\tPAYMENT" << endl;
									BUU.ShowPayMent(d,name,roundID,id);
									
				
									menu2 = MENU("1.Confirm PayMent / 2.Cancel : ",2);
									//BUU.BuyMovieSeat(id-1);
									if(menu2 == 1){
										BUU.confirmPayment(name,d,roundID,id,user);
									}
									
								}else{
									
								}
							}
							
						cout <<"\t\t\t\t\t\t\t\t===========" <<endl; 
						}else{
							menu3 = 2;
						}
						
						}while(menu3 != 2);
					}//if()
				}else{
						menu2 =MENU("2:BACK:  ",2);
				}
				
				}while(menu2 != 2);
	
				}else{
					str = "!!! Date Error !!!";
				}

		
		
		}else if(menu==2){
			system("CLS");
			cout<<endl;
			cout<<endl;			
			cout<<"\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
			cout<<"\t\t\t\t"<<"                                   *                                                                "<<endl;
			cout<<"\t\t\t\t"<<"                 *																		           "<<endl;		
			cout<<"\t\t\t\t"<<"8888888b.  8888888b.   .d88888b.  888b     d888  .d88888b. 88888888888 8888888 .d88888b.  888b    888"<<endl;
			cout<<"\t\t\t\t"<<"888   Y88b 888   Y88b d88P   Y88b 8888b   d8888 d88P   Y88b    888       888  d88P   Y88b 8888b   888"<<endl;
			cout<<"\t\t\t\t"<<"888    888 888    888 888     888 88888b.d88888 888     888    888       888  888     888 88888b  888"<<endl;
			cout<<"\t\t\t\t"<<"888   d88P 888   d88P 888     888 888Y88888P888 888     888    888       888  888     888 888Y88b 888"<<endl;
			cout<<"\t\t\t\t"<<"8888888P   8888888P   888     888 888 Y888P 888 888     888    888       888  888     888 888 Y88b888"<<endl; 
			cout<<"\t\t\t\t"<<"888        888 T88b   888     888 888  Y8P  888 888     888    888       888  888     888 888  Y88888"<<endl; 
			cout<<"\t\t\t\t"<<"888        888  T88b  Y88b. .d88P 888       888 Y88b. .d88P    888       888  Y88b. .d88P 888   Y8888"<<endl; 
			cout<<"\t\t\t\t"<<"888        888   T88b   Y88888P   888       888   Y88888P      888     8888888  Y88888P   888    Y888"<<endl;
			cout<<"\t\t\t\t"<<"       *                                             *          *                        *           "<<endl;
			cout<<"\t\t\t\t"<<"                                   *                                                                 "<<endl;
			cout<<"\t\t\t\t"<<"                 *																			        "<<endl;
			BUU.showNowPromotion();
			cout << "\t\t\t\t\t\t\t\tEnter to Bcack: ";
  			getch();
		}else if(menu == 3){
			system("CLS");
			cout<<endl;
			cout<<endl;
			cout<<"\t\t\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
			cout<<"\t\t\t\t\t\t"<<"                                   *                                                                       "<<endl;
			cout<<"\t\t\t\t\t\t"<<"                 *																				           "<<endl;
			cout<<"\t\t\t\t\t\t"<<"888    888 8888888 .d8888b. 88888888888 .d88888b.  8888888b. Y88b   d88P"<<endl;   
			cout<<"\t\t\t\t\t\t"<<"888    888   888  d88P  Y88b    888    d88P   Y88b 888   Y88b Y88b d88P "<<endl;   
			cout<<"\t\t\t\t\t\t"<<"888    888   888  Y88b.         888    888     888 888    888  Y88o88P  "<<endl;   
			cout<<"\t\t\t\t\t\t"<<"8888888888   888    Y888b.      888    888     888 888   d88P   Y888P "<<endl;     
			cout<<"\t\t\t\t\t\t"<<"888    888   888       Y88b.    888    888     888 8888888P      888  "<<endl;     
			cout<<"\t\t\t\t\t\t"<<"888    888   888         888    888    888     888 888 T88b      888  "<<endl;     
			cout<<"\t\t\t\t\t\t"<<"888    888   888  Y88b  d88P    888    Y88b. .d88P 888  T88b     888  "<<endl;     
			cout<<"\t\t\t\t\t\t"<<"888    888 8888888  Y8888P      888      Y88888P   888   T88b    888 "<<endl;
			cout<<"\t\t\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
			cout<<"\t\t\t\t\t\t"<<"                                   *                                                                       "<<endl;
			cout<<"\t\t\t\t\t\t"<<"                 *																				           "<<endl;
			BUU.ShowHistory(user);
			cout << "\n\t\t\t\t\t\t\tEnter to Bcack: ";
  			getch();
				
		} else if(menu == 4){
			goto login;
			cout <<"\tExit Programe" << endl;	
		} 
	}while(menu !=4);
	


staff:
	//ALLSTAFF
	
	int menustaff;
	do{
	system("CLS");
	cout<<"\t\t\t"<<"x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x-"<<endl;	                                                                                                                              
	cout<<"\t\t\t\t"<<"888b     d888 8888888888 888b     d888 888     888        .d8888b. 88888888888     d8888 8888888888 8888888888 "<<endl; 
	cout<<"\t\t\t\t"<<"8888b   d8888 888        8888b   d8888 888     888       d88P  Y88b    888        d88888 888        888      "<<endl;   
	cout<<"\t\t\t\t"<<"88888b.d88888 888        88888b.d88888 888     888       Y88b.         888       d88P888 888        888     "<<endl;    
	cout<<"\t\t\t\t"<<"888Y88888P888 8888888    888Y88888P888 888     888         Y888b.      888      d88P 888 8888888    8888888 "<<endl;    
	cout<<"\t\t\t\t"<<"888 Y888P 888 888        888 Y888P 888 888     888            Y88b.    888     d88P  888 888        888    "<<endl;     
	cout<<"\t\t\t\t"<<"888  Y8P  888 888        888  Y8P  888 888     888              888    888    d88P   888 888        888   "<<endl;      
	cout<<"\t\t\t\t"<<"888       888 888        888       888 Y88b. .d88P       Y88b  d88P    888   d8888888888 888        888 "<<endl;        
	cout<<"\t\t\t\t"<<"888       888 8888888888 888       888   Y88888P            Y8888P     888  d88P     888 888        888  "<<endl; 
	cout<<"\t\t\t"<<"x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x--x-"<<endl;	
					
		cout<<endl;
		cout <<"\t\t\t\t\t\t\t\t"<<"1.A D D  - A - M O V I E - I T E M"<<endl;
		cout <<"\t\t\t\t\t\t\t\t"<<"2.A D D - P R O M O T I O N" <<endl;
		cout <<"\t\t\t\t\t\t\t\t"<<"3.C H E C K - S E A T - D E T A I L S "<<endl;
	    cout <<"\t\t\t\t\t\t\t\t"<<"4.M o v i e - S a l e "<<endl;
	    cout <<"\t\t\t\t\t\t\t\t"<<"5.B A C K"<<endl;
		menustaff = MENU("Menu(1-4): ",5);
					
					  
					  	
		if(menustaff==1){
			str = " ";
			system("CLS");
			cout << endl;
			LogoSeat();
			cout << str << endl;                                                                                                      
			cout << "\t\t\t\t\t\t\t\tCheck Date: ";
			cin >> d;
			//if( d )
			
			if(CheckDate(d) && CheckDay(d)){
				do{						
					system("CLS");	
					LogoSeat();
					cout << "\t\t\t\t\t\t\t\t\tDate: " << d << endl;
					BUU.ShowListMovie(d);
					menu2 = MENU("1.AddMovie , 2.BACK: ",2);
					
					if(menu2 == 1){
						cout <<"\t\t\t\t\t\t\t\t\tMovie Name: ";
						cin >> name;
						cout <<"\t\t\t\t\t\t\t\t\tRound: ";
						cin >> round;
						
						cout <<"\t\t\t\t\t\t\t\t\tCinemaID: ";
						cin >> cinemaID;
						BUU.AddMovie(d,name,round,cinemaID);
					}//if
				
				
				}while(menu2 != 2);
	
				}else{
					str = "!!! Date Error !!!";
				}
	
			}else if(menustaff==2){
				do{
				system("CLS");
				cout<<endl;
				cout<<endl;			
				cout<<"\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
				cout<<"\t\t\t\t"<<"                                   *                                                                "<<endl;
				cout<<"\t\t\t\t"<<"                 *																		           "<<endl;	
				cout<<"\t\t\t\t"<<"8888888b.  8888888b.   .d88888b.  888b     d888  .d88888b. 88888888888 8888888 .d88888b.  888b    888"<<endl;
				cout<<"\t\t\t\t"<<"888   Y88b 888   Y88b d88P   Y88b 8888b   d8888 d88P   Y88b    888       888  d88P   Y88b 8888b   888"<<endl;
				cout<<"\t\t\t\t"<<"888    888 888    888 888     888 88888b.d88888 888     888    888       888  888     888 88888b  888"<<endl;
				cout<<"\t\t\t\t"<<"888   d88P 888   d88P 888     888 888Y88888P888 888     888    888       888  888     888 888Y88b 888"<<endl;
				cout<<"\t\t\t\t"<<"8888888P   8888888P   888     888 888 Y888P 888 888     888    888       888  888     888 888 Y88b888"<<endl; 
				cout<<"\t\t\t\t"<<"888        888 T88b   888     888 888  Y8P  888 888     888    888       888  888     888 888  Y88888"<<endl; 
				cout<<"\t\t\t\t"<<"888        888  T88b  Y88b. .d88P 888       888 Y88b. .d88P    888       888  Y88b. .d88P 888   Y8888"<<endl; 
				cout<<"\t\t\t\t"<<"888        888   T88b   Y88888P   888       888   Y88888P      888     8888888  Y88888P   888    Y888"<<endl;
				cout<<"\t\t\t\t"<<"       *                                             *          *                        *           "<<endl;
				cout<<"\t\t\t\t"<<"                                   *                                                                 "<<endl;
				cout<<"\t\t\t\t"<<"                 *																			        "<<endl;
                                                                                                      
				BUU.showPromotion();
				cout << "\t\t\t\t\t\t\t\t1.Change Promotion" <<endl;
				cout << "\t\t\t\t\t\t\t\t2.Back" <<endl;
				menu = MENU("Menu(1-2): ",2);
				if(menu == 1){
					id = MENU("ID Promotion(1-5): ",5);
					if(id != -1){
						BUU.SetNowPromotion(id-1);	
					}
				}
				
				}while(menu != 2);
			}else if(menustaff==3){
			
			str = " ";
			system("CLS");
			cout << endl;
			LogoSeat();
			cout << str << endl;                                                                                                      
			cout << "\t\t\t\t\t\t\t\tCheck Date: ";
			cin >> d;
			//if( d )
			if(CheckDate(d) && CheckDay(d)){
				do{						
					system("CLS");	
					LogoSeat();
					cout << "\t\t\t\t\t\t\t\t\tDate: " << d << endl;
					if( BUU.ShowListMovie(d) ){
					menu2 = MENU("1.CheckSeat , 2.BACK: ",2);
					
					if(menu2 == 1){
						cout << "\t\t\t\t\t\t\t\t\tName: ";
							cin >>name;
			//			cout <<"\t\t\t\t\t\t\t\tRound: ";
			//				cin >> roundID;
							
						roundID = MENU("Round: ",10);
						
						do{
						system("CLS");	
						LogoSeat();	
						cout << endl;
						//cout <<"\t\t\t\t\t\t\t\t\t====================" <<endl;
						if ( BUU.ShowMovieSeat(d,roundID,name) ){
							menu3 = MENU("1.CheckSeat // 2.BACK : ",2);
						
							if(menu3 == 1){								
								id = MENU("SeatID: ",10);
								
								//if(menu2 == 1){
								if(BUU.CheckStatusSeat(id-1) != true){
									system("CLS");
									LogoSeat();
									BUU.CheckSeat(id-1);
									cout << "\t\t\t\t\t\t\t\t\tEnter to Back: ";
  									getch();	
								}else{
										
								}
							}
							
						cout <<"\t\t\t\t\t\t\t\t===========" <<endl; 
						}else{
							menu3 = 2;
						}
						
						}while(menu3 != 2);
					}//if()
				
			 }else{
				
						menu2 =MENU("2:BACK:  ",2);
						
						
				}
				
				}while(menu2 != 2);
	
				}else{
					str = "!!! Date Error !!!";
				}
	
						
						
								  
					  }else if(menustaff == 4){
					  	do{
					  	system("CLS");
						LogoSale();
						BUU.showListMovie();
						cout <<"\t\t\t\t\t\t\t1.CheackMovieSale , 2.Back: ";
						cin >> MeNu;
						if(MeNu == "1"){
							cout <<"\t\t\t\t\t\t\tMovie Name: ";
							cin >> name;
							system("CLS");
							LogoSale();
							if( BUU.showSummaryAndDetail(name) ){
								cout << "\t\t\t\t\t\t\tEnter to Bcack: ";
  								getch();								
							}
						}
						}while(MeNu != "2");

					  }else if(menustaff == 5){
					  	goto login;
						}
				}while(menustaff!=5);
  exit:
  	system("CLS");
  	cout << "\t\t\t\t\t\t\t\t\tHello" <<endl;                                                                                                             
	

}

