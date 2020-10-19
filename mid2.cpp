#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;
class Linklist{
private:
	class node{
		public:
			//int data;
			string id;
			string name;
			string call;
			string study;
			node *link;
			node(string id,string name,string call,string study){
				//this->data = data;
				this->id=id;
				this->name=name;
				this->call=call;
				this->study=study;
				link=NULL;
			}
	};
	node *head;
	node *tail;
	int count;
public:
	Linklist(){
		this->head = NULL;
		this->tail = NULL;
		this->count = 0;
	}
/*
	~Linklist(){
		for(int i = 1; i < this->count; i++){
			node * temp = this->head;
			this->head = this->head->link;
			delete tmp;
			tmp = NULL;
		}
		this->head = NULL;
		this->tail = NULL;
	}
*/		
	
public:

	void add(string id,string name,string call,string study){
		node *NewNode = new node(id,name,call,study);
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
		node *temp;
		temp = head;
		string str;
		stringstream ss;
		cout <<"================================== BUUCHANA ==================================================" << endl;
		cout << setw(8) << left<< "No" << setw(20) << left<< "Student ID" << setw(20) << left << "Student   Name" << setw(20) << left << "Tel" << setw(20) << left<< "Faculty" << endl;
		cout <<"----------------------------------------------------------------------------------------------" << endl;
		for(int i=1;i<=count;i++){

			ss << i;
			ss >> str;
			ss.clear();
			str = str + ".";
			cout  << setw(8) << left << str ;

//			cout  << i << ".\t";
			cout  << setw(20) << left << temp->id << setw(10);

			str = temp->name;
			str = str.substr(0,str.find(' '));
			cout  << left << str << setw(10);

			str = temp->name;
			str = str.substr(str.find(' ')+1,1);
			str = str + ".";
			cout  << left << str << setw(20);	
			cout  << left << temp->call << setw(20);
/*
			str = temp->study;
			str = str.substr(11,str.size()-11);		
			cout  << left << str;	
*/
			cout  << left << temp->study;

			cout << endl;
			temp = temp->link;
		}	
		cout <<"=============================================================================================" << endl;
		cout << endl;
	}
		void read_student(){
  			string filein,name,id,tel,study;
			fstream infile;
			infile.open("student.txt");
  
      			while(getline(infile,filein)){
      				id = filein.substr(0,filein.find(','));
  					filein.erase(0,filein.find(',')+1);
				name = filein.substr(0,filein.find(','));
  					filein.erase(0,filein.find(',')+1);
  				tel = filein.substr(0,filein.find(','));
  					filein.erase(0,filein.find(',')+1);
  				study = filein.substr(11,filein.find(','));
                			filein.erase(0,filein.find(',')+1);	
				add(id,name,tel,study);
			}
		}
};
class list_staff{
private:
	class node{
		public:
			//int data;
			string id;
			string name;
			string call;
			string study;
			string pass;
			node *link;
			node(string id,string name,string call,string study,string pass){
				//this->data = data;
				this->id=id;
				this->name=name;
				this->call=call;
				this->study=study;
				this->pass = pass;
				link=NULL;
			}
	};
	node *head;
	node *tail;
	int count;
public:
	list_staff(){
		this->head = NULL;
		this->tail = NULL;
		this->count = 0;
	}
	
public:

	void add(string id,string name,string call,string study,string pass){
		node *NewNode = new node(id,name,call,study,pass);
		if(count == 0){
			head = NewNode;
			tail = head;
		}else{
			tail->link = NewNode;
			tail = tail->link;
		}
			count++; 
	}
	void menu1(){
		node *temp;
		temp = head;
		string str;
		stringstream ss;
		cout <<"================================== BUUCHANA ==================================================" << endl;
		cout << setw(8) << left<< "No" << setw(20) << left<< "Staff ID" << setw(30) << left << "Staff   Name" << setw(20) << left << "Tel" << setw(20) << left<< "Department" << endl;
		cout <<"----------------------------------------------------------------------------------------------" << endl;
		for(int i=1;i<=count;i++){

			ss << i;
			ss >> str;
			ss.clear();
			str = str + ".";
			cout  << setw(8) << left << str ;

			cout  << setw(20) << left << temp->id << setw(30);
			cout  << left << temp->name << setw(20);	

			cout  << left << temp->call << setw(20);

			str = temp->study;
			str.erase(0,11);
			cout  << left << str;

			cout << endl;
			temp = temp->link;
		}	
		cout <<"=============================================================================================" << endl;
		cout << endl;
	}
	void menu2(){
		node *temp;
		temp = head;
		string str;
		stringstream ss;
		cout <<"================================== BUUCHANA ==================================================" << endl;
		cout << setw(8) << left<< "No" << setw(20) << left<< "Academic Staff ID" ;
		cout << setw(10) << left <<"Gender" <<setw(25) << left << "Academic Staff Name" ;
		cout << setw(20) << left << "Tel" << setw(20) << left<< "Department" << endl;
		cout <<"----------------------------------------------------------------------------------------------" << endl;
		for(int i=1;i<=count;i++){
			if(temp->id[5] == '1'){
				ss << i;
				ss >> str;
				ss.clear();
				str = str + ".";
				cout  << setw(8) << left << str ;

				cout  << setw(20) << left << temp->id;
				str = temp->name;

				if(str[1] == 'r'){
					cout << setw(10) << left << "Male";
			
				}else{
					cout << setw(10) << left << "Female";
				}
				str.erase(0,str.find(' ')+1);
				str.erase(0,str.find(' ')+1);
				int a;
				if((a=str.find(' ') )== -1){
					str = temp->name;
					str.erase(0,str.find(' ')+1);
					str.erase(1,str.find(' ')-1);
					str.insert(1,".");

				}else{
					str = temp->name;
					str.erase(0,str.find(' ')+1);
					str.erase(str.find(' ')+2,a-1 ) ;
					str.insert(str.find(' ')+2,".");
				}
				cout << setw(25) << left << str ;	

				str = temp->call;
				str.erase(str.find('-'),1);
				str.erase(str.find('-'),1);	
				str.insert(0,"(");
				str.insert(4,")");
				cout  << setw(20)<< left << str << setw(20);
	
				str = temp->study;
				str.erase(0,11);
				cout  << left << str;

				cout << endl;
				temp = temp->link;
			}//if (id = 01)
		}	
		cout <<"=============================================================================================" << endl;
		cout << endl;
	}
	void menu3(){
		node *temp;
		temp = head;
		int num,n;
		string str;
		stringstream ss,s;
		cout <<"================================== BUUCHANA ==================================================" << endl;
		cout << setw(8) << left<< "No" << setw(20) << left<< "Staff ID" << setw(20) << left << "Started year" << setw(20) << left << "Encrypt password" << endl;
		cout <<"----------------------------------------------------------------------------------------------" << endl;
		for(int i=1;i<=count;i++){

			cout  << i <<".\t"<< left ;

			cout  << setw(20) << left << temp->id << setw(20);

			str = temp->id;
			ss << str[0] << str[1];
			ss >> num;
			ss.clear();
			num = num + 1957 ;
			cout  << left << num << setw(40);

			
			str = temp->pass;
			s << str.size();
			s >> n;
			s.clear();
			char tmp;
			if(n % 2 == 0){
				n=(n/2)-1;
				for(int j=0;j<n;j++){
					tmp=str[j];
					str[j]=str[(str.size()-j)-1];
					str[(str.size()-j)-1] = tmp;
				}
			}else{
				n=(n/2);
				for(int j=0;j<n;j++){
					tmp=str[j];
					str[j]=str[str.size()-j-1];
					str[(str.size()-j)-1] = tmp;
				}

			}

			cout  << left << str;

			cout << endl;
			temp = temp->link;
		}	
		cout <<"=============================================================================================" << endl;
		cout << endl;
	}

		void read_staff(){
  			string filein,name,id,tel,study,pass;
			fstream infile;
			infile.open("staff.dat");
  
      			while(getline(infile,filein)){
      				id = filein.substr(0,filein.find(','));
  					filein.erase(0,filein.find(',')+1);
				name = filein.substr(0,filein.find(','));
  					filein.erase(0,filein.find(',')+1);
  				tel = filein.substr(0,filein.find(','));
  					filein.erase(0,filein.find(',')+1);

  				study = filein.substr(0,filein.find(','));
                			filein.erase(0,filein.find(',')+1);	

  				pass = filein.substr(0,filein.find(','));
                			filein.erase(0,filein.find(',')+1);	
				add(id,name,tel,study,pass);
			}
		}

};

class buuchana{
	private:
		Linklist frame;
		list_staff staff;
	public:
		void read_data(){
			frame.read_student();
			staff.read_staff();
		}
		void show_student(){
			frame.show();
		}
		void staff_overall(){
			staff.menu1();
		}
		void staff_Academic(){
			staff.menu2();
		}
		void menu3(){
			staff.menu3();
		}	
};
int main(){
	buuchana BUU;
	int menu,menu2;
	BUU.read_data();
	do{
		cout <<"====================== BUUCHANA =============================" << endl;
		cout <<"1.Student Information" << endl;
		cout <<"2.Staff Information" << endl;
		cout <<"3.Exit" <<endl;
		cout <<"==============================================================\n\n" << endl;
		cout << "Enter: ";
		cin >> menu;
		if(menu==1){
			BUU.show_student();
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
					BUU.staff_overall();	
				}else if(menu2 ==2){
					BUU.staff_Academic();	
				}else if(menu2 ==3){
					BUU.menu3();
				
				}
			}while(menu2!=4);
		}else if(menu == 3){
			cout <<"Exit Program" << endl;	
		}

	}while(menu !=3);
}
