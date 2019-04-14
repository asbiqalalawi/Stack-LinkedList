//Asbiq Al Alawi 1817051026
#include <iostream>
#define MAX_STACK_SIZE 10

using namespace std;

struct anggota{
	int data, top;
	anggota *next;
};

class stack{
	private:
		anggota tumpuk;
		anggota *head = NULL;
		
	public:
		
		void set(){//Fungsi inisiasi
			tumpuk.top = -1;
		}
		
		bool isEmpty(){//Fungsi untuk stack kosong
			if (tumpuk.top == -1){
				return 1;
			}
			else{
				return 0;
			}
		}
		
		bool isFull(){//Fungsi untuk stack penuh
			if (tumpuk.top == MAX_STACK_SIZE -1){
				return 1;
			}
			else{
				return 0;
			}
		}
		
		void push(int input){//Fungsi untuk menambahkan stack (push)
			if (isFull()){
				cout<<"\t\t\t\t\t\tStack Full\n\n";
			}
			else{
				anggota *ptr = new anggota;
				ptr->data = input;
				ptr->next = NULL;
				if (isEmpty()){
					head = ptr;
					head->next = NULL;
				}
				else{
					ptr->next = head;
					head = ptr;
				}
				cout<<"\t\t\t\t\t\tPush berhasil\n\n";
				tumpuk.top++;
			}
		}
		
		void pop(){//Fungsi untuk mengurangi stack (pop)
			if (isEmpty()){
				cout<<"\t\t\t\t\t\tStack kosong\n\n";
			}
			else{
				anggota *ptr = new anggota;
				ptr = head;
				head = head->next;
				delete ptr;
				tumpuk.top--;
			}
		}
		
		void top(){//Fungsi untuk menentukan top stack
			if (isEmpty()){
				cout<<"\t\t\t\t\t\tStack kosong\n\n";
			}
			else{
				cout<<head->data;
			}
		}
		
		void print(){//Fungsi untuk menampilkan stack
			if (isEmpty()){
				cout<<"\t\t\t\t\t\tStack kosong\n\n";
			}
			else{
				cout<<"\t\t\t\t\t\tIsi Stack :\n";
				anggota *ptr = new anggota;
				ptr = head;
				while (ptr != NULL){
					cout<<"\t\t\t\t\t\t"<<ptr->data<<endl;
					ptr = ptr->next;
				}
				cout<<endl;
			}
		}
};

int main (){//Fungsi utama
	stack s;
	int menu, input;
	s.set();
	cout<<endl;
	cout<<"\t\t\t\t\tIMPLEMENTASI STACK MENGGUNAKAN LINKED LIST\n";
	cout<<"\t\t\t\t\t\t    By Asbiq Al Alawi\n\n";
	do{
		cout<<"\t\t\t\t\t\t==========================\n";
		cout<<"\t\t\t\t\t\t||1. Push Stack\t\t||\n";
		cout<<"\t\t\t\t\t\t||2. Pop Stack\t\t||\n";
		cout<<"\t\t\t\t\t\t||3. Print Stack\t||\n";
		cout<<"\t\t\t\t\t\t||4. Clear Stack\t||\n";
		cout<<"\t\t\t\t\t\t||5. Exit\t\t||\n";
		cout<<"\t\t\t\t\t\t==========================\n";
		cout<<"\t\t\t\t\t\tPilih : ";cin>>menu;
		cout<<endl;
		
		switch (menu){
			case 1:
				cout<<"\t\t\t\t\t\tMasukkan Angka yang ingin dipush : ";cin>>input;
				s.push(input);
				break;
			case 2:
				if (s.isEmpty()){
					cout<<"\t\t\t\t\t\tStack kosong\n\n";
				}
				else{
					cout<<"\t\t\t\t\t\t";
					s.top();
					cout<<" berhasil dipop\n\n";
					s.pop();
				}
				break;
			case 3:
				s.print();
				break;
			case 4:
				s.set();
				cout<<"\t\t\t\t\t\tStack dikosongkan\n\n";
				break;
			case 5:
				exit(0);
				break;
			default:
				cout<<"\t\t\t\t\t\tPilihan salah\n\n";
				break;
		}
	} while (menu != 5);
	return 0;
}
