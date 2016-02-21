#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "assert.h"



//constructors inint
cstack::cstack():
	n(0),
	size(STARTSIZE)
{
        a = (DATA*)calloc(STARTSIZE, sizeof(DATA));
	ASSERT(this, "stack defoult constructor")
}

cstack::cstack(int s):
	n(0),
        size(s)
{
	if(s <= 0)
	{
		printf("Calling stack constructor with bad parametr");
		exit(0);
	}
        a = (DATA*)calloc(s, (int)sizeof(DATA));
	ASSERT(this, "stack constructor")
}
cstack::cstack(const cstack& c):
        size (c.size),
        n(c.n)
{
        a = (DATA*)calloc(c.size, (int)sizeof(DATA));
        for(int i = 0; i < c.n; i++)
        	a[i] = c.a[i];
	ASSERT(this, "stack copy constructor")
}
cstack::~cstack()
{
	free(a); 
	a = NULL;
	size = 0;
	n =  0;
} 

cstack cstack::operator=(const cstack& c)
{
	size = c.size;
        n = c.n;
        a = (DATA*)calloc(c.size, (int)sizeof(DATA));
        for(int i = 0; i < c.n; i++)
                a[i] = c.a[i];
	ASSERT(this, "stack operator=")
	return *this;
}

// stack function init

void cstack::push(DATA x)
	{
		ASSERT(this, "stack push")
		if(size >= n + 1)
		{
			a[n++] = x;	
		}
		else
		{
			a = (DATA*)realloc(a ,SIZEINC * size * (int)sizeof(DATA));
			size = size * SIZEINC;
			a[n++] = x;	
		}
		ASSERT(this, "stack push")
	}

DATA cstack::pop()
	{
		ASSERT(this, "stack pop")
		if(this->is_empty())
		{
			printf("Try to pop element from empty stack\n");
			this->dump();
			exit(0);
		}
		n--;
		return a[n];
		ASSERT(this, "stack pop");
	}
DATA cstack::get_back()
	{
		ASSERT(this, "stack get_back")
		if(this->is_empty())
                {
			printf("Try to get element from empty stack\n");
                        this->dump();
                        exit(0);
                }
		return a[n - 1];
	}
// service functions init

bool cstack::is_ok()
	{
		if(n > size || n < 0) return 0;
		if(this == NULL) return 0;
       		if(a == NULL) return 0;
       	 	return 1;
			
	}
void cstack::dump() 
	{
		printf("\n\n/////////// STACK DUMP //////////\n\n");
	        if(!this->is_ok())
		{
               		printf("Bad stack\n");
			if(n > size || n < 0)
				printf("Bad size : %d or reserved memory : %d", n, size);
			else if(this == NULL)
				printf("Stack doesn't exist");
			else
				printf("Stack has NULL-pointer to array"); 
		}
     		else
     		{
               		printf(" size: %d reserved: %d pointer: %p \n", n, size, a);
			if(this->is_empty())
				printf("Stack is empty");
               		for(int i = 0; i < n; i++)
                	{
                	        printf("( %d )", a[i]);					//change %d if DATA != int
         	       	}
        	}
       		 printf("\n\n////////////////////////////////\n\n");
	}
bool cstack::is_empty()
	{
		if(n == 0)
			return 1;
		return 0;	
	}
// get-functoins init
int cstack::get_size()
	{
		return size;
	}
int cstack::get_num()
	{
		return n;
	}
