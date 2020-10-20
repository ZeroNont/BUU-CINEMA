#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<sstream>
#include<ctime>
using namespace std;
class Chair{
	public:
		string status;
		string name;
		Chair(){
			this->status="";
			this->name="";	
		}	
		void add(string status,string name){
			this->status=status;
			this->name=name;
		}	
};
class Theater{
	public:
		string TheaterID;
		Chair chair[3];
		
		Theater(){
			TheaterID = "";
			for(int i=0;i<3;i++){
				chair[i].status = "0";
				chair[i].name = "";
			}
		}
		Theaters(int index,string status,string name){
				chair[index].add(status,name);
		}
		void add(int index,string status,string name){
				chair[index].add(status,name);
		}
		void set(string TheaterID){
			this -> TheaterID = TheaterID;
		}
		void show_chair(){
			cout << "TheaterID: " << TheaterID <<endl;
			for(int i=0;i<3;i++){
				if(chair[i].status == "0"){
					cout << "X " ;
				}else{
					cout << i+1 <<" ";
				}
			}
			cout << endl;
		}
	int GetCount(){
		return 3;
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

	void show2(){
		string str;
		stringstream ss;
		cout << date <<" " <<time;
		cout << endl;
	}

	void show_chair(){
		th.show_chair();
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
			
			void show(){
				cout <<"===================" << endl;
				round.show2(); 
				cout <<"===================" << endl;
			}
			void show2(){
				cout <<"===================" << endl;	
				round.show_chair(); 
				cout <<"===================" << endl;
			}
			
	};
	
	string name;
	string np;
	string detail;
	node *head;
	node *tail;
	int count;
public:
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

	void show(){
		node *temp;
		temp = head;		

		for(int i=0;i<count;i++){
			temp->show();
			temp = temp->link;
		}			
		cout << endl;
	}
	
	void show_chair(int index){
		node *temp;
		temp = head;		

		for(int i=0;i<index;i++){
			//temp->show();
			//if()
			temp = temp->link;
		}			
		temp->show2();
		cout << endl;
	}	

		void read_data(string filename){
  			string filein,day,time,status,theaterID;
			fstream infile;
			filename = filename+".txt";
			infile.open(filename.c_str());
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
  					for(int i=0;i<3;i++){						
						status = filein.substr(0,filein.find(','));
  							filein.erase(0,filein.find(',')+1);
  						name = filein.substr(0,filein.find(','));
  							filein.erase(0,filein.find(',')+1);
  						th.add(i,status,name);
					}						
				add(day,time,th);				
				}
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
	void add2(string name){
		tail->date.add(name);		
	}
	
	node *head;
	node *tail;
	int count;
	
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
	int GetCount(){
		return count;
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
	
	void show(){
		node *temp = head;
		time_t ttime = time(0);
		tm *local_time = localtime(&ttime);
	//	cout << count << endl;
			cout<<"\n\n\n";
			cout<<"\t=============================================================================================="<<endl;
			cout<<"\t  ######   ##   ##  ##   ##        ####    ######  ##   ##  #######  ##   ##    ###      "<<endl;
			cout<<"\t   ##  ##  ##   ##  ##   ##       ##  ##     ##    ###  ##   ##   #  ### ###   ## ##    "<<endl;
			cout<<"\t   ##  ##  ##   ##  ##   ##      ##          ##    #### ##   ##      #######  ##   ##  "<<endl;
			cout<<"\t   #####   ##   ##  ##   ##      ##          ##    #######   ####    ## # ##  ##   ##  "<<endl;
			cout<<"\t   ##  ##  ##   ##  ##   ##      ##          ##    ## ####   ##      ##   ##  #######  "<<endl;
			cout<<"\t  ######    #####    #####         ####    ######  ##   ##  #######  ### ###  ##   ##  "<<endl;
			cout<<"\t==============================================================================================="<<endl;
			cout<<"\t+----------------------------------------------------------------------------------------------+"<<endl;
			cout<<"\t|  Date:"<<local_time->tm_mday<<"/"<<1 + local_time->tm_mon<<"/"<<1900 + local_time->tm_year <<"\t\t"<<"\t\t\t\t\t               "<<local_time->tm_hour;
			cout<<":"<<local_time->tm_min<<":"<<local_time->tm_sec<<"|"<<endl;
			cout<<"\t+----------------------------------------------------------------------------------------------+"<<endl;
		for(int i=1;i<=count;i++){
			cout<<"\t|"<<"  Movie name"<<":"<<temp->MovieName<<"\t\t\t\t\t\t\t\t\t       |"<<endl;
		//	cout << temp->MovieName << endl;
			temp = temp->link;
		}			
		cout<<"\t+----------------------------------------------------------------------------------------------+"<<endl;
		//cout << endl;
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
};
class Controler{
	private:
		movie m;
		Calendar Cal;
		ListMovie list;
	public:
			BuyMovie(){
				
			}
			ShowListMovie(){
				
			}
			
};

class buuchana{
	private:
		movie frame;
		DAY day[30];
		Controler Con;
		int count;
//		list_staff staff;
	public:
		void read_data(){
			
			string filein,name,id,tel,study,d;
			fstream infile;
			infile.open("date.txt");
			int i=0,j=0;
      		while(getline(infile,filein)){
      				do{
      				d=filein.substr(0,filein.find(','));
      				filein.erase(0,filein.find(',')+1);
					name = filein.substr(0,filein.find(','));			
					day[i].add(name);
					day[i].SetDate(d);
				}while( filein.find(',')  != -1);
				i++;
			}
		}
		ShowListMovie(){

		}
		void show_round(int Day,int index){
			string name;
			name = day[Day-1].get_name(index-1);
			cout << name << endl;
			frame.read_data(name);
			frame.show();
		}
		void show_student(){
		}
		void showday(int time){
			day[time-1].show();
		}
		void show_chair(int index){
			frame.show_chair(index);
		}
		
};
int main(){
	buuchana BUU;
	Calendar c;
	int menu,menu2;
	BUU.read_data();
	do{
		cout<<"\n\n\n";
		cout<<"\t=============================================================================================="<<endl;
		cout<<"\t  ######   ##   ##  ##   ##        ####    ######  ##   ##  #######  ##   ##    ###      "<<endl;
		cout<<"\t   ##  ##  ##   ##  ##   ##       ##  ##     ##    ###  ##   ##   #  ### ###   ## ##    "<<endl;
		cout<<"\t   ##  ##  ##   ##  ##   ##      ##          ##    #### ##   ##      #######  ##   ##  "<<endl;
		cout<<"\t   #####   ##   ##  ##   ##      ##          ##    #######   ####    ## # ##  ##   ##  "<<endl;
		cout<<"\t   ##  ##  ##   ##  ##   ##      ##          ##    ## ####   ##      ##   ##  #######  "<<endl;
		cout<<"\t  ######    #####    #####         ####    ######  ##   ##  #######  ### ###  ##   ##  "<<endl;
		cout<<"\t==============================================================================================="<<endl;
		cout <<"\t1.Buy ticket" << endl;
		cout <<"\t2.Check promotion" << endl;
		cout <<"\t3.Transaction History" <<endl;
		cout <<"\t4.Exit" << endl;
		cout <<"\t==============================================================\n" << endl;
		cout << "\tEnter: ";
		cin >> menu;
		if(menu==1){
			ListMovie list;
			list.read_ListMovie();
			list.show();
		}else if(menu==2){
				time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	cout<<"\n\n\n";
	cout<<"\t=============================================================================================="<<endl;
	cout<<"\t      ######   ######    #####   ##   ##   #####   ######    ####     #####   ##   ##    "<<endl;
	cout<<"\t       ##  ##   ##  ##  ##   ##  ### ###  ##   ##  # ## #     ##     ##   ##  ###  ## "<<endl;
	cout<<"\t       ##  ##   ##  ##  ##   ##  #######  ##   ##    ##       ##     ##   ##  #### ##  "<<endl;
	cout<<"\t       #####    #####   ##   ##  #######  ##   ##    ##       ##     ##   ##  ## ####"<<endl;
	cout<<"\t       ##       ## ##   ##   ##  ## # ##  ##   ##    ##       ##     ##   ##  ##  ###"<<endl;
	cout<<"\t       ##       ##  ##  ##   ##  ##   ##  ##   ##    ##       ##     ##   ##  ##   ##"<<endl;
	cout<<"\t      ####     #### ##   #####   ##   ##   #####    ####     ####     #####   ##   ##"<<endl;
	cout<<"\t==============================================================================================="<<endl;
	cout<<"\t+----------------------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|  Promotion list \t\t\t\t\t\t\t\t\t       |"<<endl;
	cout<<"\t+----------------------------------------------------------------------------------------------+"<<endl;
	cout<<"\t|"<<"  1.Buy 3 Get 4 "<<"\t\t\t\t\t\t\t\t\t       |"<<endl;
	cout<<"\t|"<<"  2.Discount 20% "<<"\t\t\t\t\t\t\t\t\t       |"<<endl;
	cout<<"\t|"<<"  3.Discount 10% "<<"\t\t\t\t\t\t\t\t\t       |"<<endl;
	cout<<"\t|"<<"  4.Discount 50% "<<"\t\t\t\t\t\t\t\t\t       |"<<endl;
	cout<<"\t|"<<"  5.No Promotion "<<"\t\t\t\t\t\t\t\t\t       |"<<endl;
	cout<<"\t+----------------------------------------------------------------------------------------------+"<<endl;
	cout<<"\t   Now Promotion : Discount 20%"<<endl;
	cout<<"\t   Enter choich  :"<<endl;
		}else if(menu == 3){
			cout <<"\tTransaction History" << endl;	
		}
		else if(menu == 4){
			cout <<"\tExit Programe" << endl;	
		}
	}while(menu !=4);
}
