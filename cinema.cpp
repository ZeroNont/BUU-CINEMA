<<<<<<< HEAD
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
};//class - Admin

class Promotion{
	private :
		string MoviePro[5];
		string UsePro;
		int count;
	public :
		
		Promotoion(){
			count = 0;
			UsePro = " ";
			/*UsePro="No Promotion";
			MoviePro[0] = "Buy 3 Get 4";
			MoviePro[1] = "Discount 10%";
			MoviePro[2] = "Discount 20%";
			MoviePro[3] = "Discount 50%";
			MoviePro[4] = "No Promotion";*/
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
				//MoviePro[count] = data;
						
				//cout << count <<" "<< GetPro(count) <<endl;
				count++;	
			}	
			
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
		bool CheckSeat(int seatID){
			return chair[seatID].CheckStatus();
		}
		string SeatData(int seatID){
			return chair[seatID].name;
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
		Admin admin;
		Member member;
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
			void readPro(){
				promo.ReadfilePromotion();
			}
			void ReadMovie(string name){
				m.read_data(name);
			//	cout << m.GetCount() <<endl;
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
			Theater ShowMovieSeat(string date,string time,string name,string id){
				m.read_data(name);
				th = m.GetTheter(date,time,id);
				return th;
			}
			Promotion GetPro(){
				return promo;
			}
	
			Theater GetTh(){
				return th;
			}
			bool CheckSeat(int seatID){
				th.CheckSeat(seatID);
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
					if(Con.GetTh().chair[i].status == "1"){
						cout << "\tX " ;
					}else{
						cout << "\t"<< i+1 <<" ";
					}
			}
			cout << endl;
		}
		void BuyMovieSeat(int seatID){
			if(Con.CheckSeat(seatID)){
				//Con.SetPayMent();
				cout << "\tFinish Pls Payment" <<endl;
			}else{
				cout << "\t!!! Pls Try Again !!!" <<endl;
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
		void show_student(){
		}
		/*
		void showday(int time){
			day[time-1].show();
		}*/
		void CheckSeat(int seatID){
			if( Con.CheckSeat(seatID) != true ){
				cout << Con.SeatData(seatID) << endl;
			}else{
				cout << "\t!!! Pls Try Again !!!" <<endl;
			}
		}
		void show_chair(int index){
		//	frame.show_chair(index);
		}
		void showPromotion(){
			string id;
			Con.readPro();
			for(int i=0;i<5;i++){
				cout << Con.GetPro().GetPro(i) << endl;
			}
		}
		int login(string name,string pass){
			if(Con.GetMember().CheckMember(name,pass) ){
				return 1;
			}else if(Con.GetAdmin().CheckAdmin(name,pass)){
				return 2;
			}else{
				return 3;
			}
		}
		void RegisMember(string name,string pass,string email,string tel){
			//Con.GetMember().loadData();
			if(Con.GetMember().CheckMember(name,pass ) != true ){
				Con.RegisMember(name,pass,email,tel);	
				
			}
		}
		void RegisAdmin(string name,string pass,string email,string tel){
			//Con.GetAdmin().loadDataAdmin();
			if(Con.GetAdmin().CheckAdmin(name,pass)){
				//Con.GetAdmin().addAdmin(name,pass,email,tel);
				Con.RegisMember(name,pass,email,tel);	
			}
			
		}
		void ReadUser(){
		//	Con.GetMember().loadData();
		//	Con.GetAdmin().loadDataAdmin();
			Con.ReadUser();
		}
};
int main(){

	UI BUU;
	Calendar c;
	int menu,menu2,mode,id;
	string d,name,round,ID;
	string user,pass,cfpass,email,tel;
	//BUU.read_data();
	
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

	do{
			cout <<endl;
			cout <<"\t\t\t\t\t\t\t\t\t"<<"1.L O G I N"<<endl;
			cout <<"\t\t\t\t\t\t\t\t\t"<<"2.R E G I S T E R"<<endl;
			cout <<"\t\t\t\t\t\t\t\t\t"<<"3.E X I T"<<endl;
			cout << endl;
			cout <<"\t\t\t\t\t\t\t\t\t"<<"Enter :" ;
			cin >> menu;
			switch(menu){
					case 1:
						
					cout <<endl;
	    			cout <<endl;
					cout<<"\t\t\t\t\t\t\t"<<"+____________________L O G I N_______________________+"<<endl;
					cout <<endl;
					cout <<"\t\t\t\t\t\t\t"<<"USERNAME :";
					cin >> user;
					cout <<"\t\t\t\t\t\t\t"<<"PASSWORD :";
					cin >> pass;
					cout<<"\t\t\t\t\t\t\t"<<"+____________________________________________________+"<<endl;
					mode = BUU.login(user,pass);
					if(mode == 1){
						goto member;	
					}else if(mode == 2){
						goto staff;
					}
					break;
					case 2:
						
					cout << endl;
	    			cout << endl;
	    			cout<<"\t\t\t\t\t\t\t"<<"+____________________ R E G I S T E R ______________________+"<<endl;
	    			cout <<endl;
	    			cout <<"\t\t\t\t\t\t\t"<<"USERNAME :";
	    			cin >> user;
					cout <<"\t\t\t\t\t\t\t"<<"PASSWORD :";
	    			cin >> pass;
					cout <<"\t\t\t\t\t\t\t"<<"CONFIRM PASSWORD :";
	    			cin >> cfpass;
					cout <<"\t\t\t\t\t\t\t"<<"E-MAIL :";
	    			cin >> email;
	    			cout <<"\t\t\t\t\t\t\t"<<"TEL :";
	    			cin >> tel;
					cout<<"\t\t\t\t\t\t\t"<<"+____________________________________________________+"<<endl;
					BUU.RegisMember(user,pass,email,tel);
	    			break;
	    			
	    			

				
				    goto member; //fogetdelet
				    break;
			}
	}while(menu != 3);

member: //fogetdelet
	do{
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
		cout <<"\t\t\t\t\t\t\t\t"<<"3.T R A N S A C T I O N - H I S T O R Y" <<endl;
		cout <<"\t\t\t\t\t\t\t\t"<<"4.E X I T" << endl;
		cout << endl;
		cout <<"\t\t\t\t\t\t\t\t"<< "Enter: ";
		cin >> menu;
	
	
		if(menu==1){

cout << endl;
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
                                                                                                                    
			 
			cout << "\t\t\t\t\t\t\t\tDate: ";
			cin >> d;
			BUU.ShowListMovie(d);
			cout << "\t\t\t\t\t\t\t\tName: ";
			cin >>name;
			cout <<"\t\t\t\t\t\t\t\tRound: ";
			cin >> round;
			cout <<"\t\t\t\t\t\t\t\tCinema: ";
			cin >> ID;
			cout <<"\t\t\t\t\t\t\t\t===========" <<endl;
			BUU.ShowMovieSeat(d,round,name,ID);			
			cout <<"\t\t\t\t\t\t\t\t===========" <<endl;
			cout << "\tSeatID: ";
			cin >> id;
			BUU.CheckSeat(id-1);
			/*
			BUU.BuyMovieSeat(id-1);
			cout << "\t\t\t\t\t\t\t\t1.Confirm PayMent / 2.Cancel : ";
			cin >> menu2;
			if(menu2 == 1){
				
			}else if(menu == 2){
				cout << "Cancel Finish" <<endl;
			}*/
		
		
		}else if(menu==2){
cout<<endl;
cout<<endl;			
cout<<"\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
cout<<"\t\t\t\t"<<"                                   *                                                                "<<endl;
cout<<"\t\t\t\t"<<"                 *																		         "<<endl;	
cout<<"\t\t\t\t"<<"8888888b.  8888888b.   .d88888b.  888b     d888  .d88888b. 88888888888 8888888 .d88888b.  888b    888"<<endl;
cout<<"\t\t\t\t"<<"888   Y88b 888   Y88b d88P   Y88b 8888b   d8888 d88P   Y88b    888       888  d88P   Y88b 8888b   888"<<endl;
cout<<"\t\t\t\t"<<"888    888 888    888 888     888 88888b.d88888 888     888    888       888  888     888 88888b  888"<<endl;
cout<<"\t\t\t\t"<<"888   d88P 888   d88P 888     888 888Y88888P888 888     888    888       888  888     888 888Y88b 888"<<endl;
cout<<"\t\t\t\t"<<"8888888P   8888888P   888     888 888 Y888P 888 888     888    888       888  888     888 888 Y88b888"<<endl; 
cout<<"\t\t\t\t"<<"888        888 T88b   888     888 888  Y8P  888 888     888    888       888  888     888 888  Y88888"<<endl; 
cout<<"\t\t\t\t"<<"888        888  T88b  Y88b. .d88P 888       888 Y88b. .d88P    888       888  Y88b. .d88P 888   Y8888"<<endl; 
cout<<"\t\t\t\t"<<"888        888   T88b   Y88888P   888       888   Y88888P      888     8888888  Y88888P   888    Y888"<<endl;
cout<<"\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
cout<<"\t\t\t\t"<<"                                   *                                                                       "<<endl;
cout<<"\t\t\t\t"<<"                 *																				           "<<endl;
                                                                                                      

	cout<<"\t\t\t\t\t\t\t\t\t"<< " Promotion list   "<<endl;
	cout<<"\t\t\t\t\t\t\t\t"<< "------------------------------------"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t"<<"  1.Buy 3 Get 4 "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t"<<"  2.Discount 20% "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t"<<"  3.Discount 10% "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t"<<"  4.Discount 50% "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t"<<"  5.No Promotion "<<endl;
	cout<<"\t   Now Promotion : Discount 20%"<<endl;
	cout<<"\t   Enter choich  :"<<endl;
	
		}else if(menu == 3){
cout<<endl;
cout<<endl;
cout<<"\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
cout<<"\t\t\t\t"<<"                                   *                                                                       "<<endl;
cout<<"\t\t\t\t"<<"                 *																				           "<<endl;
cout<<"\t\t\t\t"<<"888    888 8888888 .d8888b. 88888888888 .d88888b.  8888888b. Y88b   d88P"<<endl;   
cout<<"\t\t\t\t"<<"888    888   888  d88P  Y88b    888    d88P   Y88b 888   Y88b Y88b d88P "<<endl;   
cout<<"\t\t\t\t"<<"888    888   888  Y88b.         888    888     888 888    888  Y88o88P  "<<endl;   
cout<<"\t\t\t\t"<<"8888888888   888    Y888b.      888    888     888 888   d88P   Y888P "<<endl;     
cout<<"\t\t\t\t"<<"888    888   888       Y88b.    888    888     888 8888888P      888  "<<endl;     
cout<<"\t\t\t\t"<<"888    888   888         888    888    888     888 888 T88b      888  "<<endl;     
cout<<"\t\t\t\t"<<"888    888   888  Y88b  d88P    888    Y88b. .d88P 888  T88b     888  "<<endl;     
cout<<"\t\t\t\t"<<"888    888 8888888  Y8888P      888      Y88888P   888   T88b    888 "<<endl;
cout<<"\t\t\t\t"<<"       *                                             *          *                        *          "<<endl;
cout<<"\t\t\t\t"<<"                                   *                                                                       "<<endl;
cout<<"\t\t\t\t"<<"                 *																				           "<<endl;			
		} else if(menu == 4){
			cout <<"\tExit Programe" << endl;	
		} 
	}while(menu !=4);
	


staff:
	//ALLSTAFF
	
	int menustaff;
	
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
					cout <<"\t\t\t\t\t\t\t\t\t"<<"1.A D D  - A - M O V I E - I T E M"<<endl;
				    cout <<"\t\t\t\t\t\t\t\t\t"<<"2.A D D - P R O M O T I O N" <<endl;
				    cout <<"\t\t\t\t\t\t\t\t\t"<<"3.C H E C K - S E A T - D E T A I L S "<<endl;
				    cout <<"\t\t\t\t\t\t\t\t\t"<<"4.E X I T"<<endl;
				    cout <<"\t\t\t\t\t\t\t\t\t"<< "Enter :";    
					cin  >> menustaff;
					
					  do{
					  	
					if(menustaff==1){
						//movieitem
					}else if(menustaff==2){
						//promotion
					}else if(menustaff==3){
						//seat
					  
					  }
					  
					  }while(menustaff!=4);
                                                                                                               
	
}
		
		//}
	



=======
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
};//class - Admin

class Promotion{
	private :
		string MoviePro[5];
		string UsePro;
		int count;
	public :
		
		Promotoion(){
			count = 0;
			UsePro = " ";
			/*UsePro="No Promotion";
			MoviePro[0] = "Buy 3 Get 4";
			MoviePro[1] = "Discount 10%";
			MoviePro[2] = "Discount 20%";
			MoviePro[3] = "Discount 50%";
			MoviePro[4] = "No Promotion";*/
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
				//MoviePro[count] = data;
						
				//cout << count <<" "<< GetPro(count) <<endl;
				count++;	
			}	
			
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
		bool CheckSeat(int seatID){
			return chair[seatID].CheckStatus();
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
		Admin admin;
		Member member;
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
			void readPro(){
				promo.ReadfilePromotion();
			}
			void ReadMovie(string name){
				m.read_data(name);
			//	cout << m.GetCount() <<endl;
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
			Theater ShowMovieSeat(string date,string time,string name,string id){
				m.read_data(name);
				th = m.GetTheter(date,time,id);
				return th;
			}
			Promotion GetPro(){
				return promo;
			}
	
			Theater GetTh(){
				return th;
			}
			bool CheckSeat(int seatID){
				th.CheckSeat(seatID);
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
					if(Con.GetTh().chair[i].status == "1"){
						cout << "\tX " ;
					}else{
						cout << "\t"<< i+1 <<" ";
					}
			}
			cout << endl;
		}
		void BuyMovieSeat(int seatID){
			if(Con.CheckSeat(seatID)){
				//Con.SetPayMent();
				cout << "\tFinish Pls Payment" <<endl;
			}else{
				cout << "\t!!! Pls Try Again !!!" <<endl;
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
			string id;
			Con.readPro();
			for(int i=0;i<5;i++){
				cout << Con.GetPro().GetPro(i) << endl;
			}
		}
		int login(string name,string pass){
			if(Con.GetMember().CheckMember(name,pass) ){
				return 1;
			}else if(Con.GetAdmin().CheckAdmin(name,pass)){
				return 2;
			}else{
				return 3;
			}
		}
		void RegisMember(string name,string pass,string email,string tel){
			//Con.GetMember().loadData();
			if(Con.GetMember().CheckMember(name,pass ) != true ){
				Con.RegisMember(name,pass,email,tel);	
				
			}
		}
		void RegisAdmin(string name,string pass,string email,string tel){
			//Con.GetAdmin().loadDataAdmin();
			if(Con.GetAdmin().CheckAdmin(name,pass)){
				//Con.GetAdmin().addAdmin(name,pass,email,tel);
				Con.RegisMember(name,pass,email,tel);	
			}
			
		}
		void ReadUser(){
		//	Con.GetMember().loadData();
		//	Con.GetAdmin().loadDataAdmin();
			Con.ReadUser();
		}
};
int main(){
	UI BUU;
	Calendar c;
	BUU.ReadUser();
	int menu,menu2,id,mode;
	string d,name,round,ID;
	string user,pass,cfpass,email,tel;
	//BUU.read_data();
	//cout << "hello2" <<endl;
	//BUU.showPromotion();
	do{
			cout << "================== Cinema ========================="<<endl;
			cout <<"1.Login"<<endl;
			cout <<"2.Register"<<endl;
			cout <<"3.Exit"<<endl;
			cout << "==================================================="<<endl;
			cout <<"Enter :" ;
			cin >> menu;
			switch(menu){
					case 1:
	    			
					cout<<"===========Login=========="<<endl;
					cout <<"Username :";
					cin >> user;
					
					cout <<"Password :";
					cin >> pass;
					cout <<"========================="<<endl;
					mode = BUU.login(user,pass);
					//cout << mode << endl;
					if(mode == 1){
						
						goto member;	
					}else if(mode == 2){
						//goto admin;
					}
				    break;
				    
				    
					case 2:
	    				
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
	    			BUU.RegisMember(user,pass,email,tel);
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
			cout <<"\t===========" <<endl;
			BUU.ShowMovieSeat(d,round,name,ID);			
			cout <<"\t===========" <<endl;
			cout << "\tSeatID: ";
			cin >> id;
			BUU.BuyMovieSeat(id-1);
			cout << "\t1.Confirm PayMent / 2.Cancel : ";
			cin >> menu2;
			if(menu2 == 1){
				
			}else if(menu == 2){
				cout << "Cancel Finish" <<endl;
			}
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



>>>>>>> aa5d45f9e9cdd4afcaa4fe1f00d0767486b34672
