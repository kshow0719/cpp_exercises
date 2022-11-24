// ArrayStack.h

#include <string>
#include <iostream>
using namespace std;

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class pop_exception:public runtime_error{
public:
    pop_exception() : runtime_error("Pop exception.") {};
};

class top_exception:public runtime_error{
public:
    top_exception() : runtime_error("Top exception.") {};
};

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

    // ************************** Q2 **************************
    // Q2 コピーコンストラクタ
    ArrayStack(const ArrayStack& array){
        this->_num_items = array._num_items;
        this->_allocated_size = array._allocated_size;
        this->_items = new string[array._allocated_size];
        for (int i = 0; i < array._allocated_size; i++){
            this->_items[i] = array._items[i];
        }
    }

    // Q2 コピーの代入演算子
    ArrayStack& operator=(const ArrayStack& array){
        // 自身の代入チェック
        if (this != &array){
            this->_num_items = array._num_items;
            this->_allocated_size = array._allocated_size;
            this->_items = new string[array._allocated_size];
            for (int i = 0; i < array._allocated_size; i++){
                this->_items[i] = array._items[i];
            }
        }
        return *this;
    }

    // ************************** Q3 **************************
    // Q3 移動コンストラクタ
    ArrayStack(ArrayStack&& array){
        // 要素の移動
        this->_num_items = array._num_items;
        this->_allocated_size = array._allocated_size;
        this->_items = array._items;
        // 参照を断ち切る
        array._num_items = 0;
        array._allocated_size = 0;
        array._items = 0;
    }

    // Q3 移動の代入演算子
    ArrayStack& operator=(const ArrayStack&& array){
        // 自身の代入チェック
        if (this != &array){
            this->_num_items = array._num_items;
            this->_allocated_size = array._allocated_size;
            this->_items = array._items;
        }
        return *this;
    }

    explicit ArrayStack(int _allocated_size){
        this->_num_items = 0;
        this->_allocated_size = _allocated_size;
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
        try{
            if(empty()){
                throw pop_exception();
            }
            _num_items--;
            if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
        }
        catch(const runtime_error& e){
            cerr << e.what() << endl;
        }
    }

    // Access the top-most item 
    std::string top() {
        if(empty()) throw top_exception();
        return _items[_num_items-1];
    };

    // Check if the stack is empty 
    bool empty() const { return _num_items == 0; }

    // Return the number of elements in the stack 
    int size() const { return _num_items; }
};

#endif // ARRAY_STACK_H