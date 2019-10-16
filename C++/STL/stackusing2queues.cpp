#include <bits/stdc++.h>

using namespace std;

class Stack{
	
	queue<int> q1, q2;

	int Stacksize;

public:
	Stack(){
		Stacksize=0;
	}

	// Ensure that the newly inserted element is always at the front of queue so that in dequeue the newly inserted element is the
	// the first to get dequeued
	void pushinefficient(int x){
		q2.push(x);
		Stacksize++;

		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}

		queue<int> q=q1;
		q1=q2;
		q2=q;
	}

	void popefficient(){
		if(q1.empty())
			return;

		int x=q1.front();
		printf("Popped element is: %d\n",x);
		q1.pop();
		Stacksize--;
	}

	void pushefficient(int x){
		q1.push(x);
		Stacksize++;
	}

	void popinefficient(){
		if(q1.empty())
			return;

		while(q1.size() >1){
			q2.push(q1.front());
			q1.pop();
		}

		int x=q1.front();
		printf("Popped element is: %d\n",x);
		
		q1.pop();
		
		queue <int> q= q1;
		q1=q2;
		q2=q;

		Stacksize--;

	}

	int topforpopefficient(){
		if(q1.empty())
			return -1;
		else
		//printf("Top element in the Stack: %d\n",q1.front());
			return q1.front();
	}

	//Notice that top for push efficient is also inefficient along with pop inefficient
	int topforpushefficient(){
		if(q1.empty())
			return -1;

		while(q1.size() >1){
			q2.push(q1.front());
			q1.pop();
		}

		return q1.front();
	}

	int size(){
		return Stacksize;
	}

};


int main() 
{ 
    Stack s; 
    s.pushinefficient(1); 
    s.pushinefficient(2); 
    s.pushinefficient(3); 
  /*
    cout << "current size: " << s.size()  
         << endl; 
    cout << s.topforpopefficient() << endl; 
    s.popefficient(); 
    cout << s.topforpopefficient() << endl; 
    s.popefficient(); 
    cout << s.topforpopefficient() << endl; 
  
    cout << "current size: " << s.size()  
         << endl;

    cout << endl;
*/
    s.pushefficient(1); 
    s.pushefficient(2); 
    s.pushefficient(3); 
  
    cout << "current size: " << s.size()  
         << endl; 
    cout <<"current top:"<< s.topforpushefficient() << endl; 
    s.popinefficient(); 
    cout <<"current top:"<< s.topforpushefficient() << endl; 
    s.popinefficient(); 
    cout <<"current top:"<< s.topforpushefficient() << endl; 
  
    cout << "current size: " << s.size()  
         << endl;       
    return 0; 
}


