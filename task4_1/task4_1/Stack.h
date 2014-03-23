/*
*@file		stack.h
*@brief		describes class Stack for storing data
*/

#ifndef STACK_H_
#define STACK_H_



class Stack
{
public:
	Stack(void);
	~Stack(void);

	bool isEmpty(void);
	void Push(char element);
	char Pop(void);

private:
	unsigned int size;
	char* stack;
};

#endif

