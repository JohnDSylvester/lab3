#include "FibVec.h"
#include <iostream>
// This provides exception types:
#include <stdexcept>

// FibVec Function Implementations
size_t FibVec::fibNewSize(int element){
	if(element >= 2){
		return fibNewSize(element - 1) + fibNewSize(element -2);
	}
	return element;
}

size_t FibVec::capacity() const{
	return cap;
}

size_t FibVec::count() const{
        return cou;
}

void FibVec::reSize(int* &array, size_t size){
	int* array2 = new int[size];
	for(size_t i = 0; i < cou; i++){
		array2[i] = array[i];	
	}

	delete [] array;

	array = array2;

	cap = size;
	//std::cout << "Resized to " << cap << std::endl;
}

void FibVec::push(int value){
	if(cou == cap){
		ele++;
		reSize(array, fibNewSize(ele));
	}

	array[int(cou)] = value;
	cou++;
}

int FibVec::pop(){
	try{
		if(cou <= 0){
		throw (std::underflow_error("Underflow"));
		}
		int val = array[int(cou-1)];
		cou--;
		if(cou < fibNewSize(ele-2)){
                	ele--;
                	reSize(array, fibNewSize(ele));
        	}
		return val;
	}
	catch(const std::underflow_error& e){
		std::cout << "Underflow.\n";
		exit(1);
	}
}

int FibVec::lookup(size_t index) const{
        try
	{
	if(index > cou-1){
                throw (std::out_of_range("Index out of range"));
                }
	return array[index];
	}
	catch(const std::out_of_range& e){
                std::cout << "Index out of range.";
		exit(1);
        }
}

FibVec::FibVec(){
	size_t current = fibNewSize(2);
	array = new int[current];
	cap = current;
	ele = 2;
	cou = 0;
}
FibVec::~FibVec(){
	delete [] array;
}

void FibVec::insert(int value, size_t index){
        if(cou == cap){
                ele++;
                reSize(array, fibNewSize(ele));
        }
        if(cou != 0){
        for(unsigned int i = cou; i > index; i--){
                array[i] = array[i-1];
        }
        }
        array[index] = value;

        cou++;
}

int FibVec::remove(size_t index){
        try{
                if(cou <= 0){
                throw (std::underflow_error("Underflow"));
                }
                int val = array[int(index)];
		cou--;
                if(cou < fibNewSize(ele-2)){
			cou++;
                        ele--;
                        reSize(array, fibNewSize(ele));
                }
		cou--;
                for(unsigned int i = index; i < cou; i++){
                array[i] = array[i+1];
        }
                return val;
        }
        catch(const std::underflow_error& e){
                std::cout << "Underflow.\n";
                exit(1);
        }
}
