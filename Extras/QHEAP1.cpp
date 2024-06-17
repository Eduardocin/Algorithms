#include <iostream>
#include <vector>

using namespace std;

template<typename V>
class MinHeap{
private:
    vector<V> arr;
    int heapSize;

    void heapfyUp(){
        int i = heapSize;
        while(i > 1 && arr[i/2] > arr[i]){
            swap(arr[i], arr[i/2]);
            i = i/2;
        }
    }


    void heapfyDown(){
        for (int i = heapSize/2; i > 0; i--){
            int k = i;
            V element = arr[k];
            bool heap = false;
            

            while(!heap && 2*k <= heapSize){
                int j = 2*k;
                if(j < heapSize){
                    if(arr[j] < arr[j+1]){
                        j++;
                    }
                }
                if(element <= arr[j]){
                    heap = true;
                }
                else{
                    arr[k] = arr[j];
                    k = j;
                }
            }
            arr[k] = element;
        }
    }
public:
    MinHeap(): heapSize(0){
        arr.push_back(V());
    }

    ~MinHeap(){}

    
    void insert(V element){
        arr.push_back(element);
        heapSize++;
        heapfyUp();
    }

    V findMin(){
        return arr[1];
    }

    V deleteMin(){
        V min = arr[1];
        arr[1] = arr[heapSize];
        heapSize--;
        arr.pop_back();
        heapfyDown();
        return min;
    }

    int getSize(){
        return heapSize;
    }

};

int main(){
    int numQueries, QueryType, element;
    cin >> numQueries;

    MinHeap<int>* minHeap = new MinHeap<int>();

    for (int i = 0; i < numQueries; i++){
        cin >> QueryType;
        if(QueryType == 1){
            cin >> element;
            minHeap->insert(element);
        }
        else if(QueryType == 2){
            if(minHeap->getSize() > 0){
                cin >> element;
                minHeap->deleteMin();
                }
        }
        else if(QueryType == 3){
            cout << minHeap->findMin() << endl;
        }
    }

    return 0;
}