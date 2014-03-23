/*
*@file		stack.h
*@brief		implements class Stack for storing data
*/
#include "stdafx.h"
#include "Stack.h"

Stack::Stack(void)
:size(0)
,stack(NULL)
{
}


Stack::~Stack(void)
{
	delete(stack);
}


/**
* @brief				This function checks if stack is empty
* @param	void
* @return	bool		Return true if stack is empty, otherwise return false
*/
bool Stack::isEmpty(void)
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
* @brief				Function put the element into stack
* @param	char		Element you want to push into stack
* @return	void		
*/
void Stack::Push(char element)
{
	++size;
	char* new_stack = new char[size];
	memcpy(new_stack, stack, size - 1);
	delete(stack);
	stack = new_stack;
	stack[size - 1] = element;
}

/**
* @brief				This function returns element that is on the top of stack and decrease the size of stack on 1
* @param	void		
* @return	char		Returns ERROR if stack is empty
						Otherwise: returns the element that is on the top of stack 					
*/
char Stack::Pop(void)
{
	//assert(size);
	if (isEmpty())
	{
		return ERROR;
	}

	char top = stack[size - 1];
	--size;
	char* new_stack = new char[size];
	memcpy(new_stack, stack, size);
	delete(stack);
	stack = new_stack;

	return top;
}

