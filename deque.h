#ifndef RAILROAD_DEQUE_H
#define RAILROAD_DEQUE_H

#include "dequeInterface.h"
using namespace std;
template<typename T>
class Deque : public dequeInterface<T>
{
private:
    size_t capacity;
    size_t num_items;
    size_t front_index;
    size_t rear_index;
    T* the_data;
    static const size_t DEFAULT_CAPACITY = 4;
public:
    Deque(void) : capacity(DEFAULT_CAPACITY),
                  num_items(0),
                  front_index(0),
                  rear_index(DEFAULT_CAPACITY - 1),
                  the_data(new T[DEFAULT_CAPACITY]) {}
    ~Deque(){delete[] the_data; }



    void push_front(const T& data)
    {
        if (num_items == capacity) reallocate();
        ++num_items;

        if (front_index == 0)
        {
            front_index = capacity - 1;
        }
        if (front_index != 0)
        {
            front_index = (front_index - 1);
        }
        the_data[front_index] = data;
        return;
    }

    void push_back(const T& data) {
        if (num_items == capacity) reallocate();
        ++num_items;
        rear_index = (rear_index + 1) % capacity;
        the_data[rear_index] = data;
        return;

    }

    void reallocate()
    {
        T* new_data = new T[2 * capacity];
        for (size_t i = 0; i < num_items; ++i)
        {
            new_data[i] = the_data[front_index];
            front_index = (front_index + 1) % capacity;
        }
        front_index = 0;
        rear_index = num_items - 1;
        capacity = 2 * capacity;
        swap(the_data, new_data);
        delete[] new_data;
        return;
    }
    void pop_front()
    {
        const T temp;
        temp = the_data[front_index];
        front_index += 1;
        return temp;
    }
    void pop_back()
    {
        const T temp;
        temp = the_data[rear_index];
        rear_index -= 1;
        return temp;
    }
    const T& front()
    {
        return front_index;
    }
    const T& back()
    {
        return rear_index;
    }
    bool empty() const
    {
        if(num_items == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    const T& at(size_t index)
    {
        return (index + front_index) % capacity;
    }
    string toString() const
    {
        stringstream out;
        for (int i = front_index; i < num_items; i++)
        {
            out << the_data[i % capacity] << " ";
        }
    }


};
#endif //RAILROAD_DEQUE_H
