#include<iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;
struct node
{

	int month;
	int date;
	node* next;
	node* prev;
}
*start;
class DE_QUEUE
{
private:
	node* curr = NULL;
	node* temp = NULL;
	node* head = NULL;
	node* current_ptr = NULL;
	int count;
public:
	node* Push_Back(int month,int date) {
		if (head == NULL) {
			temp = new node;
			temp->month = month;
			temp->date = date;
			head = temp;
			current_ptr = temp;
			temp->next = NULL;
			temp->prev = NULL;
		}
		else {
			current_ptr = temp;
			temp = new node;
			temp->month = month;
			temp->date = date;
			current_ptr->next = temp;
			temp->prev = current_ptr;
			temp->next = NULL;
			Priority();
		}
		return temp;
	}
	void Priority() {
		node* temp = head;
		node* temp1 = head;
		while (temp != NULL) {
			temp1 = temp->next;
			while (temp1 != NULL) {
				if (temp->month > temp1->month) {
					swap(temp->month, temp1->month);
					swap(temp->date, temp1->date);
				}
				else if(temp->month == temp1->month) {
					if (temp->date > temp1->date) {
						swap(temp->month, temp1->month);
						swap(temp->date, temp1->date);
					}
				}
				temp1 = temp1->next;
			}
			temp = temp->next;
		}
	}
	void Pop_Front() {
		node* temp = head;
		if (head == NULL) {
			cout << "Queue is Empty\n";
			this_thread::sleep_for(chrono::milliseconds(950));
		}
		if (temp == NULL) {
			return;
		}
		temp = temp->next;
		delete head;
		if (temp == NULL) {
			head = NULL;
			return;
		}
		head = temp;
		temp->prev = NULL;
	};
	void display_dlist() {
		node* Temp = head;
		if (head == NULL) {
			cout << "Queue is Empty";
			return;
		}
		cout << "Your Data is ";
		cout << endl;
		cout << "-------------------";
		cout << endl;
		while (Temp != NULL) {
			cout <<"Month "<<Temp->month << " Date "<<Temp->date;
			cout << endl;
			Temp = Temp->next;
		}
		cout << endl;
	}
	bool is_empty();
	DE_QUEUE()
	{
		head = NULL;
		current_ptr = NULL; //constructor for my class
		count = 0;
	}
	~DE_QUEUE() {
		current_ptr = head;
		while (current_ptr != NULL)
		{
			node* next = current_ptr->next;
			delete current_ptr;
			current_ptr = next;
		}
	}
};
int main() {
	node* NODE = NULL;
	DE_QUEUE a;
	while (true) {
		system("cls");
		cout << "Enter the Respective Number to PerFrom The operation\n";
		cout << "-----------------------------------------------------\n";
		cout << "1 Enqueue\n";
		cout << "2 Dequeue\n";
		cout << "3 Display\n";
		cout << "4 End\n";
		cout << "--------------------------------------------------------\n";
		int in;
		cin >> in;
		if (in == 1) {
			system("cls");
			cout << "Enter the Month and day respectively you want to Insert\n";
			cout << "-------------------------------------------------------\n";
			int date;
			int month;
			cin >> month;
			cin >> date;
			NODE = a.Push_Back(month,date);
		}
		if (in == 2) {
			a.Pop_Front();
		}
		if (in == 3) {
			system("cls");
			a.display_dlist();
			this_thread::sleep_for(chrono::milliseconds(950));
		}
		if (in == 4) {
			break;
		}
	}
	system("pause");
	return 0;
}