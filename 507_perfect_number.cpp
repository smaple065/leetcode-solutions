/*
https://leetcode.com/problems/perfect-number/
maples1
1/29/2019
*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
	int sum = 0;

	//implement linked list to hold divisors
	struct nodeType
	{
		int info;
		nodeType *link;
	};

	nodeType *first, *newNode, *current, *last;
	first = nullptr;
	last = nullptr;

	for (int i = 1; i < num; i++)
	{
		//add number to list if it divides num
		if (num%i == 0)
		{
			newNode = new nodeType;
			newNode->info = i;
			newNode->link = nullptr;
			if (first == nullptr)
			{
				first = newNode;
				last = newNode;
			}
			else
			{
				last->link = newNode;
				last = newNode;
			}
		}
	}

	//Add up all divisors
	current = first;
	while (current != nullptr)
	{
		sum += current->info;
		current = current->link;
	}

	if (sum == num && sum != 0)
		return true;
	else
		return false;
    }
};