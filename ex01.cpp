#include<iostream>
#include<cstdlib>
using namespace std;
class array{
private:
	int capacity;
	int count;
	int *item;
	int *arry;
public:
	array(int size){
		arry = new int[size];
		capacity = size;
		count = 0;
		for(int i;i<capacity;i++){
			arry[i]=0;
		}
	}
	~array(){
		delete[] arry;
	}
	void add(int value){
			set(indexOf(0),value);
	}
	void add(int index,int val){
		if(index > count){
			set(index,val);
		}else{		
			for(int i=count ;i >= index ;i--){
				arry[i]=arry[i-1];
			}
			set(index,val);
		}
		
	}
	int get(int index){
		return arry[index];
	}
	void set(int index,int val){
		arry[index]=val;
		count++;
	}
	void remove(int value){
		for(int i=0;i<capacity;i++){
			if(arry[i] == value){
				set(i,0);
			}
		}
	}
	int indexOf(int value){
		for(int i=0;i<capacity;i++){	
			if(arry[i] == value){
				return i;
			}
			if(i==capacity){
				return -1;
			}
		}
	}
	int size(){
		return count;
	}
	int max_size(){
		return capacity;
	}
	bool isEmpty(){
		if(count != 0){
			return true;
		}else{
			return false;
		}
	}
	bool isFull(){
		if(capacity == count){
			return true;
		}else{
			return false;
		}
	}
	void show(){
		for(int i=0;i<capacity;i++){
			if(arry[i] != 0){
				cout << arry[i] << "  ";
			}else{
				cout << "_  ";
			}
		}		
		cout << endl;
	}
};
int main(){
int n,key,i,val,index;
	system("clear");
	cout << "N of array: ";
	cin >> n;
	array frame(n);	
	do{
		system("clear");
		frame.show();
		cout << "\n1.add\n2.add_index\n3.Remove\n4.Exit\nMenu: ";
		cin >> key;	
		if(frame.isFull() != true ){
			if(key == 1){
				cout << "Val: ";
				cin >> val;
				frame.add(val);
			}else if(key == 2){
				cout << "Index,Val: ";
				cin >> index >>  val;
				frame.add(index,val);
			}	
		}
		if(key == 3){
			cout << "Val: ";
			cin >> val;
			frame.remove(val);
		}
	}while(key != 4);
	system("clear");
	cout << " THANK YOU " << endl;
//	frame.get(2;)

}
