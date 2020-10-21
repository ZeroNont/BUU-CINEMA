#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<sstream>
#include<ctime>
using namespace std;
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
		}//funtion - addMember
		void loadData(){
			string UserName,Password,Email,Tel,filein;
			ifstream infile;
			infile.open("member.txt");
				while(getline(infile,filein)){
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
};
class Promotion{
	private :
		string UsePro;
		int count;
	public :
		string MoviePro[5];
		Promotoion(){
			UsePro="No Promotion";
			MoviePro[0] = "Buy 3 Get 4";
			MoviePro[1] = "Discount 10%";
			MoviePro[2] = "Discount 20%";
			MoviePro[3] = "Discount 50%";
			MoviePro[4] = "No Promotion";
		}
		string GetUsePro(){
			return UsePro;
		}	
		void SetUsePro(int index){
			UsePro = MoviePro[index];			
		}
		int size(){
			return count;
		}
		/*Promotion SearchPromotion(){
			return Promotion;
		}*/
};
class Payment{
	
};
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
	Theater GetTheter(string date,string time,string id){
		node *temp = head;		

		for(int i=0;i<count;i++){
			if( (temp->round.GetDate() == date && temp->round.GetTime() == time) && temp->round.GetID() == id){
				return temp->round.GetTheater();
			}else{
				temp = temp->link;
			}	
		}			
		cout << endl;
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

		void read_data(string filename){
			count = 0;
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
	
	DAY SearchDate(string date){
		node *temp = head;
		for(int i=0;i<count;i++){
			if( temp->date.get_date() == date){
				return temp->date;
			}
		}
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
		Theater th;
		Calendar Cal;
		ListMovie list;
		Promotion promo;
	public:
			void readfile(){
				//m.read_data();
				list.read_ListMovie();
				Cal.read_date();
			} 
			void ReadMovie(string name){
				m.read_data(name);
			//	cout << m.GetCount() <<endl;
			}
			movie GetMovie(){
				return m;
			}
			BuyMovie(){
				
			}
			DAY SearchDate(string date){
				return Cal.SearchDate(date);
			}
			Theater ShowMovieSeat(string date,string time,string name,string id){
				m.read_data(name);
				th = m.GetTheter(date,time,id);
				return th;
			}
			Promotion GetPro(){
				return promo;
			}
			int getsize(){
				return promo.size();
			}			
			Theater GetTh(){
				return th;
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
		void ShowListMovie(string date){
			string name;
			cout << "\n\t=================\n" <<endl;
			for(int i=0;i<Con.SearchDate(date).GetCount();i++){
				name = Con.SearchDate(date).get_name(i);
				cout <<"\tMovieName: "<< name <<endl;
								
					Con.ReadMovie(name);
					for(int i=0;i<Con.GetMovie().GetCount();i++){
						if(Con.GetMovie().GetRound(i).GetDate() == date){
							cout <<"\tRound: "<< Con.GetMovie().GetRound(i).GetTime() <<"  CINEMA:" << Con.GetMovie().GetRound(i).GetID() << endl;
						}
					}
					cout << "\n\t=================\n" <<endl;
			}
		}
		void ShowMovieSeat(string date,string time,string name,string id){
			//Con.GetMovie().read_data(name);
			for (int i=0 ;i<Con.ShowMovieSeat(date,time,name,id).GetCount();i++){
					if(Con.GetTh().chair[i].status == "0"){
						cout << "\tX " ;
					}else{
						cout << "\t"<< i+1 <<" ";
					}
			}
			cout << endl;
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
		void show_student(){
		}
		/*
		void showday(int time){
			day[time-1].show();
		}*/
		
		void show_chair(int index){
		//	frame.show_chair(index);
		}
		void showPromotion(){
			for(int i=0;i<Con.getsize();i++){
			//	cout << Con.GetPro.name[i] << endl;
			}
		}
};
int main(){
	UI BUU;
	Calendar c;
	int menu,menu2;
	string d,name,round,ID;
	string user,pass,cfpass,email,tel;
	//BUU.read_data();
	do{
			cout << "================== Cinema ========================="<<endl;
			cout <<"1.Registration"<<endl;
			cout <<"2.Login"<<endl;
			cout <<"3.Exit"<<endl;
			cout << "==================================================="<<endl;
			cout <<"Enter :" ;
			cin >> menu;
			switch(menu){
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
	    			break;
	    			
	    			
					case 2:
	    			
					cout<<"===========Login=========="<<endl;
					cout <<"Username :";
					cin >> user;
					
					cout <<"Password :";
					cin >> pass;
					cout <<"========================="<<endl;
				
				    goto member;
				    break;
			}
	}while(menu != 3);

member:
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
		cout <<"\t-Member Menu-" << endl;
		cout <<"\t1.Buy ticket" << endl;
		cout <<"\t2.Check promotion//Comming Soon" << endl;
		cout <<"\t3.Transaction History//Comming Soon" <<endl;
		cout <<"\t4.Exit" << endl;
		cout <<"\t==============================================================\n" << endl;
		cout << "\tEnter: ";
		cin >> menu;
		if(menu==1){
			cout<<"\n\n\n";
			cout<<"\t=============================================================================================="<<endl;
			cout<<"\t  ######   ##   ##  ##   ##        ####    ######  ##   ##  #######  ##   ##    ###      "<<endl;
			cout<<"\t   ##  ##  ##   ##  ##   ##       ##  ##     ##    ###  ##   ##   #  ### ###   ## ##    "<<endl;
			cout<<"\t   ##  ##  ##   ##  ##   ##      ##          ##    #### ##   ##      #######  ##   ##  "<<endl;
			cout<<"\t   #####   ##   ##  ##   ##      ##          ##    #######   ####    ## # ##  ##   ##  "<<endl;
			cout<<"\t   ##  ##  ##   ##  ##   ##      ##          ##    ## ####   ##      ##   ##  #######  "<<endl;
			cout<<"\t  ######    #####    #####         ####    ######  ##   ##  #######  ### ###  ##   ##  "<<endl;
			cout<<"\t==============================================================================================="<<endl;
			//showlist
			cout << "\tDate: ";
			cin >> d;
			BUU.ShowListMovie(d);
			cout << "\tName: ";
			cin >>name;
			cout <<"\tRound: ";
			cin >> round;
			cout <<"\tCinema: ";
			cin >> ID;
			BUU.ShowMovieSeat(d,round,name,ID);
			cout<<"\t+----------------------------------------------------------------------------------------------+"<<endl;
		}else if(menu==2){
		/*
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
		} */
	}
	}while(menu !=4);
}

