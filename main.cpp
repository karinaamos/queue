#include "Queue.h"


int main(){
    Queue<int> arr(10);
    arr.Push(55);
    arr.Push(35);
    std::cout << arr.Pop()<<"\n"<<arr.Pop();

    try {
        std::cout <<"\n"<< arr.Pop();
    }
    catch(const char* a){
        std::cout << a;
    }
    
    arr.Push(54);
    arr.Push(34);
    std::cout <<"\n"<< arr.Pop()<<"\n"<<arr.Pop();

    

    return 0;
}