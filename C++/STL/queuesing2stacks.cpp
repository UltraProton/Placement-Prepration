#include <bits/stdc++.h>
#include <stack>
#include <iostream>

using namespace std;

class Queue{
	
	int queuesize;
	stack <int> s1, s2;

	public:
		Queue(){
			queuesize=0;
		}

		void enqueueefficient(int x){
			s1.push(x);
			queuesize++;
		}

		void dequeueinefficient(){
			if(s1.empty() && s2.empty()){
				cout<< "Queue is empty." <<endl;
				return;
			}

			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}

				int x= s2.top();
				cout <<"dequeued element is :" << x <<endl;
				s2.pop();
			}

			else{

				int x= s2.top();
				cout <<"dequeued element is :" << x <<endl;
				s2.pop();
			}

			queuesize--;
		}

		int front(){
			if(s1.empty() && s2.empty()){
				cout<< "Queue is empty." <<endl;
				return -1;
			}

			if(s2.empty()){
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}

				return s2.top();
			}

		else
			return s2.top();
		}

		int rear(){
			if(s1.empty() && s2.empty()){
				cout<< "Queue is empty." <<endl;
				return -1;
			}

			if(!s1.empty())
				return s1.top();

			else{
				while(!s2.empty()){
					s1.push(s2.top());
					s2.pop();
				}

			return s1.top(); 
			}
		}


		void enqueueinefficient(int x){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}

			s2.push(x);

			while(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}

			queuesize++;
		}

		void dequeueefficient(){
			if(s1.empty()){
				cout<< "Queue is empty." <<endl;
				return;
			}

			else{
				int x= s1.top();
				cout << "Dequeued element is :" << x << endl;
				s1.pop(); 
			}

			queuesize--;
		}

		int rear1(){
			if(s1.empty()){
				cout << "Queue is empty" <<endl;
				return -1;
			}

			else{
				while(!s1.empty()){
					s2.push(s1.top());
					s1.pop();
				}

				int x= s2.top();

				while(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}

			return x;
			}
		}

		int front1(){
			if(s1.empty()){
				cout << "Queue is empty." <<endl;
				return -1;
			}

			else{
				return s1.top();
			}

		}
};

int main(int argc, char const *argv[])
{
	Queue  q;

	q.enqueueefficient(1);
	q.enqueueefficient(2);
	q.enqueueefficient(3);

	cout << "Front:" << q.front() << endl;

	q.dequeueinefficient();

	cout << "Front:" << q.front() << endl;
    cout << "Rear:" << q.rear() << endl;

    q.dequeueinefficient();
	q.dequeueinefficient();
	q.dequeueinefficient();
	q.dequeueinefficient();

	cout << "Front:" << q.front() << endl;
    cout << "Rear:" << q.rear() << endl;

   cout <<"\n\n";


    q.enqueueinefficient(1);
	q.enqueueinefficient(2);
	q.enqueueinefficient(3);

	cout << "Front:" << q.front1() << endl;

	q.dequeueefficient();

	cout << "Front:" << q.front1() << endl;
    cout << "Rear:" << q.rear1() << endl;

    q.dequeueefficient();
	q.dequeueefficient();
	q.dequeueefficient();
	q.dequeueefficient();

	cout << "Front:" << q.front1() << endl;
    cout << "Rear:" << q.rear1() << endl;

    cout <<endl;
    cout <<"\n";
	return 0;
}