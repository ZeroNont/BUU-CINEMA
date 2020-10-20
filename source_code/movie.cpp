#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<sstream>
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
		//		cout << chair[i].status << " ";
		
				if(chair[i].status == "0"){
					cout << "X " ;
				}else{
					cout << i+1 <<" ";
				}
		
		//		if(i==4){
		///			cout << endl;
		//		}
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
		
		/*
		for(int i=1;i<=count;i++){
			cout <<"Round: "<< temp->time << endl;
			temp = temp->link;
		}			
		*/
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
		cout << count << endl;
		for(int i=1;i<=count;i++){
			cout << "==========" << endl;
			cout << temp->MovieName << endl;
			cout << "==========" << endl;
			temp = temp->link;
		}			
		cout << endl;
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
//		list_staff staff;
	public:
		void read_data(){
			
			string filein,name,id,tel,study;
			fstream infile;
			infile.open("day.txt");
			int i=0;
      		while(getline(infile,filein)){
      			
      			do{
      				filein.erase(0,filein.find(',')+1);
					name = filein.substr(0,filein.find(','));			
					day[i].add(name);
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
			//frame.show_chair(index);
		}
		void show_student(){
			//frame.show();
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
		cout <<"====================== BUUCHANA =============================" << endl;
		cout <<"1.Buy_Movie" << endl;
		cout <<"2.Staff Information" << endl;
		cout <<"3.Exit" <<endl;
		cout <<"==============================================================\n\n" << endl;
		cout << "Enter: ";
		cin >> menu;
		if(menu==1){
			/*
			//Date_Movie
			c.read_date();
			c.show();
			*/
			//List_Movie
			ListMovie list;
			list.read_ListMovie();
			list.show();
			
			
			/*
			//Movie
			int time,index;
			cout <<"day:";
			cin >> time;
			BUU.showday(time);
			cin >> index;
			BUU.show_round(time,index);
			cout <<"Round: ";
			cin >> index;
			BUU.show_chair(index-1);
			cin>> index;
			//BUU.show_student();
			*/
		}else if(menu==2){
			do{
				cout <<"====================== BUUCHANA =============================" << endl;
				cout <<"1.Overall staff information" << endl;
				cout <<"2.Academic staff Infotmation" << endl;
				cout <<"3.User account menu" << endl;
				cout <<"4.Return to main menu" << endl;
				cout <<"====================== BUUCHANA =============================" << endl;
				cout << "Enter: ";
				cin >> menu2;
				if(menu2 == 1){
				//	BUU.staff_overall();	
				}else if(menu2 ==2){
				//	BUU.staff_Academic();	
				}else if(menu2 ==3){
				//	BUU.menu3();
				
				}
			}while(menu2!=4);
		}else if(menu == 3){
			cout <<"Exit Program" << endl;	
		}

	}while(menu !=3);
}
