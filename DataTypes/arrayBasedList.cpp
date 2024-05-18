#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
struct ArrayList{
private:
    int max_size;
    int size;
    int curr;
    T* array;

public:
    /**
     * Constructor to initialize the ArrayList with a specified size.
     * param tamanho The maximum size of the ArrayList.
     */
    ArrayList(int tamanho){
        max_size = tamanho;
        size = curr = 0;
        array = new T[max_size];
    }

    /**
     * Inserts a value at the current position in the ArrayList.
     * param value The value to be inserted.
     * throws std::overflow_error if the ArrayList is full.
     */
    void insert(T value ){
        if(size >= max_size){throw std::overflow_error("ArrayList is full");}
        int i = size;
        while(i > curr){
            array[i] = array[i - 1];
            i--;
        }
        array[curr] = value;
        size++;
    }

    /**
     * Moves the current position to the next element in the ArrayList.
     */
    void next(){
        if(curr < size) { curr++;}
    }
    
    /**
     * Moves the current position to the previous element in the ArrayList.
     */
    void prev(){
        if(curr > 0) { curr--;}
    }

    /**
     * Counts the occurrences of a value in the ArrayList.
     * param value The value to be counted.
     * return The number of occurrences of the value.
     */
    int count(T value){
        int count = 0;
        for(int i = 0; i < size; i++){
            if(array[i] == value){
                count++;
            }
        }
        return count;
    }

    /**
     * Removes the element at the current position in the ArrayList.
     * return The removed element.
     * throws std::out_of_range if the current position is out of range.
     */
    T remove(){
        if ((curr < 0) || ( curr >= size)){throw std::out_of_range("Current position is out of range");}
        int i = curr;
        T it = array[curr];
        while(i < size - 1){
            array[i] = array[i + 1];
            i++;
        }
        size--;
        return it;
    }
};

/**
 * Main function to demonstrate the usage of ArrayList.
 * return Exit status of the program.
 */

int main() {
    ArrayList<int> r(10);
    r.insert(2);
    r.insert(3);
    r.insert(4);

    r.remove(); // remove based on current position

    cout << r.count(2) << endl; // count based on current position

    return 0;
}