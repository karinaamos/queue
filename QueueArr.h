#include <iostream>

template <class T>
class QueueArr{
private:
    T* _array;
    size_t _size;
    size_t _startId;
    size_t _findId;
public:
    QueueArr(size_t size = 25){
        _array = new T[size];
        _size = size;
        _startId = 0;
        _findId = 0;
    } 
    void Push(const T& elem){ //принимает элемент и не возвращает
        if (_findId + 1 != _size){
            _array[_findId] = elem;
            _findId ++;
        }
        else{
            throw "mnogo hochesh";
        }
    }
    T Pop(){ //удаляет из контейнера первый элемент
        if (Empty()){
            throw "empty";
        }
        T a;
        a = _array[_startId ++];
        if (_startId == _findId){
            _findId = 0;
            _startId = 0;
        }
        return a;
    }
    bool Empty(){ //проверка на пустоту
        return (_findId == 0);
    }
    size_t GetSize(){ //получение размера

    }
    T& Front(){ //возвращает первый элемиент, без удаления из контейнера
        return _array[_startId];
    }
    T& Back(){ //возвращает последний элемиент, без удаления из контейнера
        return _array[_findId];
    }
};