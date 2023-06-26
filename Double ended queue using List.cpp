#include<iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;
struct node
{
	int data;
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
	node* Push_Back(int value) {
		if (head == NULL) {
			temp = new node;
			temp->data = value;
			head = temp;
			current_ptr = temp;
			temp->next = NULL;
			temp->prev = NULL;
		}
		else {
			current_ptr = temp;
			temp = new node;
			temp->data = value;
			current_ptr->next = temp;
			temp->prev = current_ptr;
			temp->next = NULL;
		}
		return temp;
	}
	node* Push_Front(int value) {
		bool p = false;
		node* temp2 = nullptr;
		node* temp = new node;
		temp->data = value;
		if (head == NULL) {
			head = temp;
			current_ptr = temp;
			this->temp = this->current_ptr;
			head->next = NULL;
			head->prev = NULL;
			return head;
		}
		else {
			temp2 = head;
			head = temp;
			if (this->current_ptr == temp2 && current_ptr->next==NULL) {
				this->current_ptr->prev = temp2;
				p = true;

			}
			head->data = value;
			head->next = temp2;
			temp2->prev = temp;
			head->prev = NULL;
			if (temp2 == this->current_ptr && p==true) {
				this->current_ptr = this->current_ptr->prev;
				p = false;
			}
			return temp;
		}
	};
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
	node* Pop_Back(node* NODE) {
		node* temp = this->current_ptr;
		node* temp2 = temp;
		
		if (head == NULL) {
			cout << "Queue is Empty\n";
			this_thread::sleep_for(chrono::milliseconds(950));
			return NULL;
		}
		if (temp->next == NULL && temp->prev == NULL) {
			delete head;
			this->head = NULL;
			this->current_ptr = NULL;
			this->temp = NULL;
		}
		else {
			temp = temp->next;
			delete temp;
			if (temp2 == head) {
				temp2->next = NULL;
				temp2->prev = NULL;
				return NULL;
			}
			else {
				temp2->next = NULL;
				temp2 = temp2->prev;
				this->current_ptr = temp2;
			}
		}
		return temp;
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
			cout << Temp->data << " ";
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
		cout << "1 Push Back\n";
		cout << "2 Push Front\n";
		cout << "3 pop_Back\n";
		cout << "4 Pop_Front\n";
		cout << "5 Display\n";
		cout << "6 End\n";
		cout << "--------------------------------------------------------\n";
		int in;
		cin >> in;
		if (in == 1) {
			system("cls");
			cout << "Enter the Data you want to Insert\n";
			cout << "-----------------------------------------------\n";
			int data1;
			cin >> data1;
			NODE = a.Push_Back(data1);
		}
		if (in == 2) {
			system("cls");
			cout << "Enter the Data you want to Insert\n";
			cout << "----------------------------------\n";
			int data;
			cin >> data;
			NODE = a.Push_Front(data);
		}
		if (in == 3) {
			NODE = a.Pop_Back(NODE);
		}
		if (in == 4) {
			a.Pop_Front();
		}
		if (in == 5) {
			system("cls");
			a.display_dlist();
			this_thread::sleep_for(chrono::milliseconds(950));
		}
		if (in == 6) {
			break;
		}
	}
	system("pause");
	return 0;
}
