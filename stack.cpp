#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "assert.h"
#include "logger.cpp"


//constructors inint
cstack::cstack():
	n_(0),
	size_(STARTSIZE)
{
	$1
        array_ = (DATA*)calloc(STARTSIZE, sizeof(DATA));
	ASSERT(this)
}

cstack::cstack(int s):
	n_(0),
        size_(s)
{
	$1
	if(s <= 0)
	{
		printf("Calling stack constructor with bad parametr");
		exit(0);
	}
        array_ = (DATA*)calloc(s, (int)sizeof(DATA));
	ASSERT(this)
}

cstack::cstack(const cstack& c):
        size_(c.size_),
        n_(c.n_)
{
	$1
        array_ = (DATA*)calloc(size_, (int)sizeof(DATA));
        for(int i = 0; i < n_; i++)
        	array_[i] = c.array_[i];
	ASSERT(this)
}
cstack::~cstack()
{
	free(array_); 
	array_ = NULL;
	size_ = 0;
	n_ =  0;
} 

cstack cstack::operator=(const cstack& c)
{
	$1
	size_ = c.size_;
        n_ = c.n_;
        array_ = (DATA*)calloc(size_, (int)sizeof(DATA));
        for(int i = 0; i < n_; i++)
                array_[i] = c.array_[i];
	ASSERT(this)
	return *this;
}

// stack function init

void cstack::push(DATA x)
	{
		$1
		ASSERT(this)
		if(size_ >= n_ + 1)
		{
			array_[n_++] = x;	
		}
		else
		{
			array_ = (DATA*)realloc(array_ ,SIZEINC * size_ * (int)sizeof(DATA));
			size_ = size_ * SIZEINC;
			array_[n_++] = x;	
		}
		ASSERT(this)
	}

DATA cstack::pop()
	{
		$1
		ASSERT(this)
		if(this->is_empty())
		{
			printf("Try to pop element from empty stack\n");
			this->dump();
			exit(0);
		}
		n_--;
		return array_[n_];
		ASSERT(this);
	}
DATA cstack::get_back()
	{
		$1
		ASSERT(this)
		if(this->is_empty())
                {
			printf("Try to get element from empty stack\n");
                        this->dump();
                        exit(0);
                }
		return array_[n_ - 1];
	}
// service functions init

bool cstack::is_ok()
	{
		$1
		if(n_ > size_ || n_ < 0) return 0;
		if(this == NULL) return 0;
       		if(array_ == NULL) return 0;
       	 	return 1;
			
	}
void cstack::dump() 
	{
		$1
		printf("\n\n/////////// STACK DUMP //////////\n\n");
	        if(!this->is_ok())
		{
               		printf("Bad stack\n");
			if(n_ > size_ || n_ < 0)
				printf("Bad size : %d or reserved memory : %d", n_, size_);
			else if(this == NULL)
				printf("Stack doesn't exist");
			else
				printf("Stack has NULL-pointer to array"); 
		}
     		else
     		{
               		printf(" size: %d reserved: %d pointer: %p \n", n_, size_, array_);
			if(this->is_empty())
				printf("Stack is empty");
               		for(int i = 0; i < n_; i++)
                	{
                	        printf("( %d )", array_[i]);					//change %d if DATA != int
         	       	}
        	}
       		 printf("\n\n////////////////////////////////\n\n");
	}
bool cstack::is_empty()
	{
		$1
		if(n_ == 0)
			return 1;
		return 0;	
	}
// get-functoins init
int cstack::get_size()
	{
		$1
		return size_;
	}
int cstack::get_num()
	{
		$1
		return n_;
	}
DATA cstack::get_element(int i)
	{
		$1
		if(i >= n_)
		{
			printf("Try to get unexisting element");
			exit(0);
		}
		return array_[i];
	}
