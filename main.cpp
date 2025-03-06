#include "Queue.h"
using namespace std;

int main(){
    Queue<int> q = Queue<int>(20);
    q.Push(10);
    q.Push(15);
    //q.Pop();
    q.Print();
    cout<<q.Empty()<<endl;
    cout<<q.Full()<<endl;



    return 0;
}