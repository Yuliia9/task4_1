/*
*@file		Functions.cpp
*@brief		implements functions declared in file task4_1.h and used in file task4_1.cpp
*/
#include "stdafx.h"
#include "Stack.h"
#include <string>


void Interface(void)
{
	puts("------------------------------------------------------------------------");
	puts("Welcome to the genius \"brackets helper\".");
	puts("Enter expression and program will check if you placed brackets properly. ");
	puts("Program made by Yuliia Lyubchik.");
	puts("------------------------------------------------------------------------\n");
}


unsigned char Input(char** expression)
{
	do
	{
		char temp;
		int count = 0;
		printf("Please enter expression for checking: ");
		do
		{
			scanf("%c", &temp);

			++count;
			*expression = (char*)realloc(*expression, count * sizeof(char));

			if (*expression != NULL) 
			{
				*(*expression + count - 1) = temp;
			}
			else 
			{
				free(expression);
				puts("Error (re)allocating memory. \n");
				return ERROR;
			}

		} 
		while (temp != '\n' && temp != EOF);

		fflush(stdin);
		*(*expression + count - 1) = '\0';

	} 
	while (expression == NULL || strlen(*expression) == 0);

	return SUCCESS;
}


unsigned char Checking(const char* expression)
{
	Stack brackets;

	unsigned int i;
	unsigned char retCode;

	for (i = 0; i < strlen(expression); ++i)
	{
		switch (expression[i])
		{

		case '(':
			brackets.Push('(');
			break;

		case '{':
			brackets.Push('{');
			break;

		case '[':
			brackets.Push('[');
			break;

		case ')':
			retCode = brackets.Pop();
			if (retCode != '(')
			{
				return FAIL;
			}
			break;

		case '}':
			retCode = brackets.Pop();
			if (retCode != '{')
			{
				return FAIL;
			}
			break;

		case ']':
			retCode = brackets.Pop();
			if (retCode != '[')
			{
				return FAIL;
			}
			break;
		}
	}

	if (!brackets.isEmpty())
	{
		return FAIL;
	}
	return SUCCESS;
}