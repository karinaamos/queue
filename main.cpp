#include "QueueArr.h"


int main(){
    QueueArr<int> arr(10);
    arr.Push(10);
    arr.Push(55);
    std::cout<<arr.Pop()<<" "<<arr.Pop();
    std::cout<<arr.Pop();

    
}