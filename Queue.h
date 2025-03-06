#include <iostream>
using namespace std;

template <typename T>
class Queue{
private:
    T* _data;
    size_t _startIndex;
    size_t _endIndex;
    size_t _size;
    size_t _capacity;

public:
    Queue(size_t size): _size(size), _data(new T[size]), _capacity(0), _startIndex(0), _endIndex(0){}

    ~Queue(){
        delete[] _data;
    }

    void Pop(){
        if (Empty())
            throw "Queue is empty!";
        _capacity--;
        _startIndex = (_startIndex + 1) % _size;
    }

    void Push(const T& elem) {
        if (Full())
            throw "Queue is full!";
        _data[_endIndex] = elem;
        _endIndex = (_endIndex + 1) % _size;
        _capacity++;
    }

    void Print() {
        if (Empty())
        std::cout << "Queue is empty!" << std::endl;
        for (size_t i = 0; i < _capacity; i++) {
            std::cout << _data[(_startIndex + i) % _size] << std::endl;
        }
    }
    size_t Size(){
        return _size;
    }
    size_t Capacity(){
        return _capacity;
    }
    bool Empty(){
        return _capacity == 0;
    }
    bool Full(){
        return _capacity == _size;
    }
    T& Front(){
        if (Empty())
            throw "Queue is empty!";
        return _data[_startIndex];
    }
    T& Back(){
        if (Empty())
            throw "Queue is empty!";
        return _data[_endIndex];
    }
};
