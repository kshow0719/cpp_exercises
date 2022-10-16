#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include "stack.h"

// Check whether the stack is empty 
bool Stack::empty(){
    if (_top == -1){
        return true;
    }
    else{
        return false;
    }
}

// Check whether the stack is full
bool Stack::full(){
    if (_top == _max_size - 1){
        return true;
    }
    else{
        return false;
    }
}

// Return the number of elements in the stack
int Stack::size(){
    return _top + 1;
}

// Insert element on top
// print an error message on std::cerr when overflow
void Stack::push(Point xy){
    if (full()){
        std::cerr << "Error: The stack is full."<< std::endl;
    }
    else{
        _data[++_top] = xy;
    }
}

// Remove element on top
// print an error message on std::cerr when underflow
void Stack::pop(){
    if (empty()){
        std::cerr << "Error: The stack is empty."<< std::endl;
    }
    else{
        _top--;
    }
}

// Acces the topmost element
Point Stack::top(){
    return _data[_top];
}