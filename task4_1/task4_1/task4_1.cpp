/*
* @file			task4_1.cpp
* @brief		Program checks if brackets in expression placed properly

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/


#include "stdafx.h"
#include "task4_1.h"
#include "Stack.h"
#include <string>
#include <iostream>


int main(void)
{
	Interface();

	unsigned char retCode;
	char* expression = NULL;

	retCode = Input(&expression);
	if (retCode == ERROR)
	{
		puts("Error occurs while trying to input string.\n");
		return (int)ERROR;
	}

	retCode = Checking(expression);
	if (retCode == FAIL)
	{
		puts("Brackets placed improperly.\n");
	}
	else if (retCode == SUCCESS)
	{
		puts("Brackets placed properly. \n");
	}

	free(expression);
	system("pause");
	return MAIN_SUCCESS;
}

