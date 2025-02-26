#include <iostream>

template <class T>
class Queue{
private:
    size_t _size; // максимальный размер очереди 
    T* _array;
    size_t _start;//индекс начального
    size_t _end;//индекс последнего +1    
public:
    Queue(size_t size): _size(size), _start(0), _end(0){ //конструктор
        _array=new T [size];
    }

    void Push(const T& elem){ //добавление элемента в конец очереди
        if (IsFull()){ //проверка на полноту
            throw "queue is full";
        }
        _array[_end] = elem; // добавление элемента в конец очереди
        _end = (_end + 1) % _size; // увеличение индекса конца очереди на 1
    }
    
    T Pop(){ // удаление элемента из начала очереди
        if(IsEmpty()){ //проверка на пустоту
            throw "queue is empty";
        }
        T elem = _array[_start]; // сохранение значения элемента из начала очереди
        _start = (_start + 1) % _size; // увеличение индекса конца очереди на 1
        return elem;
    }
    
    size_t GetSize() const { // получение текущего размера очереди
        if (_end >= _start) {
            return _end - _start;
        } 
        else {
            return _size - _start + _end;
        }
    } 

    T& Front(){  // получение ссылки на элемент в начале очереди 
        return _array[_start];   
    }
    
    T& Back() { // получение ссылки на элемент в конце очереди 
        size_t back; //индекс последнего элемента
        if (_end == 0) { //значит либо пустая очередь, либо back в конце очереди
            back = _size - 1;
        } 
        else { //иначе индекс back просто на 1 меньше конца
            back = _end - 1;
        }   
        return _array[back];
    } 
    
    bool IsEmpty() const{ //проверка на пустоту
        return _start == _end;
    }

    bool IsFull() const { //проверка на полноту
        return ((_end + 1) % _size) == _start;
    }
        
    ~Queue(){ //деструктор
        delete [] _array;
    }
};