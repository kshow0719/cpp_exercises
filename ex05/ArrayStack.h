// ArrayStack.h

#include <string>
#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack {
private:
    int _num_items; // number of items in the stack
    std::string* _items; // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size) {
        if (max_size==0) max_size++;
        
        // Move stack to a new array of size max
        _allocated_size = max_size;
        std::string* temp = new std::string[max_size];
        // Copy 
        for (int i = 0; i < _num_items; ++i) {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

public:
    // Constructors:
    // Default constructor 
    ArrayStack(){
        this->_num_items = 0;
        this->_allocated_size = 0;
        this->_items = NULL;
    }
    /* COMPLETE ... initialize _num_items to 0, _allocated_size to 0, and
     * set _items to the null pointer, 
     */

    // Q2 コピーコンストラクタ
    ArrayStack(const ArrayStack& array){
        this->_num_items = array._num_items;
        this->_allocated_size = array._allocated_size;
        this->_items = array._items;
    }

    explicit ArrayStack(int _allocated_size){
        this->_num_items = 0;
        std::string* AS = new std::string[_allocated_size];
        this->_items = AS;
    }
    /* COMPLETE ... initialize _num_items to 0, 
     * pre-allocate memory for an array of size allocated_size
     * and make _items point to it */

    // Destructor:
    ~ArrayStack() {
        // COMPLETE
        delete[] this->_items;
    }

    // Push item to the stack 
    void push(const std::string& item) {
        if (_num_items == _allocated_size) resize(2*_allocated_size);
        _items[_num_items++] = item;
    }

    // Pop an item 
    void pop() {
        _num_items--;
        if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
    }

    // Access the top-most item 
    std::string top() {
        return _items[_num_items-1];
    }

    // Check if the stack is empty 
    bool empty() const { return _num_items == 0; }

    // Return the number of elements in the stack 
    int size() const { return _num_items; }
};

#endif // ARRAY_STACK_H