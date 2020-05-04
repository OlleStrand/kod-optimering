#pragma once
#include <vector>

void Lists()
{
	std::vector<int> myList;
	myList.push_back(1);
	int i = 1;
	myList[0] = i;
	i = myList[0];
}