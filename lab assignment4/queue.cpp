#include<iostream>
using namespace std;
#define MAX 5
int queueArr[MAX];
int front = -1;
int rear = -1;

bool isempty(){
    return front == -1;
}
bool isfull(){
    return rear == MAX-1;
}
void enqueue(int value){
    if(isfull()){
        cout<<"queue overflow"<<endl;
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        queueArr[rear] = value;
        cout<<value<<" is inserted to the queue"<<endl;
    }
}
void dequeue(){
    if(isempty()){
        cout<<"queue underflow"<<endl;
        return;
    }
        cout<<queueArr[front]<<" is removed from the queue"<<endl;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

}
void display(){
    if(isempty()){
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<"queue elements are: ";
    for(int i=front; i<=rear; i++){
        cout<<queueArr[i]<<" ";
    }
    cout<<endl;
}
void peek(){
    if(isempty()){
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<"front element is: "<<queueArr[front]<<endl;
}
int main(){
    int choice, value;
    do{
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. IsEmpty"<<endl;
        cout<<"4. IsFull"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Peek"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Enter value to enqueue: ";
            cin>>value;
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;
        
        case 3:
            if(isempty()){
                cout<<"queue is empty"<<endl;
            }
            else{
                cout<<"queue is not empty"<<endl;
            }
            break;

        case 4:
            if(isfull()){
                cout<<"queue is full"<<endl;
            }
            else{
                cout<<"queue is not full"<<endl;
            }
            break;

        case 5:
            display();
            break;

        case 6:
            peek();
            break;

        case 7:
            cout<<"Exiting..."<<endl;
            break;

        default:
            cout<<"Invalid choice"<<endl;
        }
    }while(choice != 7);

    return 0;
}