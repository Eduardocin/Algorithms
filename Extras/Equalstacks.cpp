#include <iostream>
#include <stdexcept>

using namespace std;

// stack structure
template <typename E>
struct Node{
    E data;
    Node* next;

    Node(E it, Node* nextnode): data(it), next(nextnode) {}
};

template<typename E>
struct Stack{
private:
    Node<E>* top;
    int size;

public:
    Stack(){
        top = NULL;
        size = 0;
    }

    void push(E it){
        top = new Node<E>(it, top);
        size++;
        }
    
    int sum() const{
        int sum = 0;
        Node<E>* temp = top;
        while (temp != NULL) {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    bool sumUntil(E it) const{
        int sum = 0;
        Node<E>* temp = top;
        while(temp != NULL && sum < it){
            sum += temp->data;
            if(sum == it){return true;}
            temp = temp->next;
        }
        return false;
    }

    void print() const{
        Node<E>* temp = top;
        while(temp!= NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    E pop(){
        if(top == NULL){throw runtime_error("Stack is empty");}
        E it = top->data;
        Node<E>* temp = top;
        top = top->next;
        delete temp;
        size--;
        return it;

    }
};


int main(){
    //receive 3 inputs from the user
    int array[3];
    int sumarray[3];
    int value;
    for(int i = 0; i < 3; i++){
        cin >> array[i];
    }
    //create a stack for each integer
    Stack<int> stack[3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < array[i]; j++) {
            cin >> value;
            stack[i].push(value);
        }
        }

    //sum each stack values
    for(int i = 0; i < 3; i++){
        sumarray[i] = stack[i].sum();
        }


    // encontrar o menor valor
    int min = sumarray[0];
    int index = 0;
    for(int i = 0; i < 3; i++){
        if(sumarray[i] < min){
            min = sumarray[i];
            index= i;
        }
    }
    
    stack[index].print();

    //try equalize the stacks
    int check = 0;
    bool equalize = false;
    if (min != 0){
        while(!equalize){
            check = 0;
            for(int i = 0; i < 3; i++){                
                if(stack[i].sumUntil(min)){
                    check += 1;
                }
            }
            if(check == 3){
                cout << min << endl;
                equalize = true;
                }
            else{
                min -= stack[index].pop();
            }
        }
    }else{cout << 0 << endl;}

    

    return 0;
}
