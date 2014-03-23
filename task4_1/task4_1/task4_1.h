/*
*@file		task4_1.h
*@brief		header file that defines prototypes of functions used in file task4_1.cpp
*/
#ifndef TASK4_1_H_
#define TASK4_1_H_




#include "stdafx.h"


/**
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface(void);


/*
* @brief					Function for inputing string
* @param	[in/out]		char** riadok - a pointer to null pointer to string for sentences
*
*@return	unsigned char	Return ERROR if error occurs while trying to allocate memory for string
							Return SUCCESS if string was inputed
*/
unsigned char Input(char** riadok);


/*
* @brief					Function for checking if brackets placed properly
* @param	[in]			const char* expression - a pointer to expression nedded to be checked
*
*@return	unsigned char	Return ERROR if error occurs while trying to get access to expression
							Return SUCCESS if brackets were placed properly
							Return FAIL if brackets were placed improperly
*/
unsigned char Checking(const char* expression);

#endif