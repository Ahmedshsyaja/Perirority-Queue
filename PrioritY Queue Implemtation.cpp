#include<iostream>
using namespace std;
int Size = -1;
struct Array {
	int data;
	int priority;
};
Array queue[10];
int head = -1;
int Rear = -1;
int parity = 11;
void enqueue(int value) {
	head = 0;
	Rear = (Rear + 1)%10;
	queue[Rear].data = value;
	queue[Rear].priority = Rear;
	// setting Ascending priority
	for (int i = head; i <= Rear; i++) {
		for (int j = i + 1; j <= Rear; j++) {
			if (queue[i].data < queue[j].data) {
				queue[i].priority = parity;
				swap(queue[i].data, queue[j].data);
				parity = parity + 1;
			}
		}
	}
}
int peek() {
	int Higestpr = -1;
	int value;
	int index;
	for (int i = head; i <= Rear; i++) {
		if (queue[i].priority > Higestpr) {
			index = i;
			Higestpr = queue[i].priority;
			value = queue[i].data;
		}
	 }
	return value;
}
void Dequeue() {
	head = (head + 1)%10;
}
bool is_Empty() {
	if (Rear == -1 || head==-1) {
		return true;
	}
	else {
		return false;
	}
}
void Display() {
	if (is_Empty() == true) {
		cout << "Queue is Empty";
		return;
	}
	cout << endl;
	for (int i = head; i <= Rear; i++) {
		cout <<"   Data ::"<< queue[i].data << " Priority " << queue[i].priority;
	}
	cout << endl;
}
int main() {
	while (true) {
		cout << "Enter the Respective Number To Perform Operation\n";
		cout << "1 Enqueue\n";
		cout << "2 Dequeue\n";
		cout << "3 To display\n";
		cout << "4 To End the programme\n";
		int in;
		cin >> in;
		if (in == 1) {
			cout << "Enter the Data You want To Insert\n";
			cout << "------------------------------------";
			cout << endl;
			int data;
			cin >> data;
			enqueue(data);
		}if (in == 2) {
			Dequeue();
		}if (in == 3) {
			Display();
		}if (in == 4) {
			break;
		}
	}

}

