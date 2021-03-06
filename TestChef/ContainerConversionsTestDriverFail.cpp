#include "ContainerConversionsTestDriverFail.h"

//////////////////////////////////////////////////////
// ContainerConversionsTestDriverPass.cpp			//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
*
* Implementation of ContainerConversionsTestDriverPass.h
* 
* This class is part of the TEST functions that the TestHarness runs through
* The function used in TEST passes the elements of one type of container
* into a different type of container.
*
*/

bool ContainerConversionsTestDriverFail::TEST() {
	ContainerConversions converter{};
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::list<int> lst = converter.vectorToList(vec);
	int i = 1;							// this will cause a fail
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		if (vec[i] != *it) return false;
		++i;
	}
	return true;
}