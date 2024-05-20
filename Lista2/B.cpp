#include <iostream>
#include <tuple>

using namespace std;


template<typename T>
struct Node{
    T data;
    Node<T> *next;

    Node(): next(nullptr){}
    Node(T data): data(data), next(nullptr){}
};

template<typename T>
struct Queue{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    Queue(): head(new Node<T>()), tail(head), size(0){}

    void enqueue(T it){
        tail->next = new Node<T>(it);
        tail = tail->next;
        size++;
    }

    T dequeue(){
        if(size == 0){throw runtime_error("Queue is empty");}
        T it = head->next->data;
        Node<T> *temp = head->next;
        head->next = head->next->next;
        if(head->next == nullptr){tail = head;}
        size--;
        delete temp;
        return it;
        }

    int length(){return size;}

    T front() const{
        if(size == 0){throw runtime_error("Queue is empty");}
        return head->next->data;
    }

};

int main(){
    int numtests, numstudents, arrivetime, leavetime, time;
    
    cin >> numtests;
    for(int i = 0; i < numtests; i++){
        cin >> numstudents;
        Queue<tuple<int, int>>  students;


        for(int j = 0; j < numstudents; j++){
            cin >> arrivetime >> leavetime;
            students.enqueue(make_tuple(arrivetime, leavetime));
        }


        time = 1;
        while(students.length() > 0){
            auto [arrivetime, leavetime] = students.front();
            students.dequeue();

            if(time < arrivetime){
                time = arrivetime;
            }
            
            if(time <= leavetime){
                cout << time << " ";
                time ++;
            }else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}