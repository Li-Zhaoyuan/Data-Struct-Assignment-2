#include "DetectMemoryLeak.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    <Li Zhaoyuan>
 *  \date      2015 
 *  \note      <150592K>
 */


// Balanced parenthesis
 bool Brackets(const string& input)
{
	 stack<char> cstack;
	 bool brackets = false;
	 if (input.empty())
	 {
		 return false;
	 }
	
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '(' || input[i] == '[' || input[i] == '{' || input[i] == '<')//opening of all the different brackets
		{
			cstack.push(input[i]);
		}
		else if (cstack.empty() == true)
		{
			return false;
		}
		else if (input[i] == ')' || input[i] == ']' || input[i] == '}' || input[i] == '>')//closing of all the different brackets
		{
			if ((cstack.top() == '(' && input[i] == ')')
				|| (cstack.top() == '[' && input[i] == ']')
				|| (cstack.top() == '{' && input[i] == '}')
				|| (cstack.top() == '<' && input[i] == '>'))
			{
				brackets = true;
			}
			else
			{
				brackets = false;
			}
			if (cstack.empty() == true || brackets == false)
			{
				return false;
			}
			else
			{
				cstack.pop();
			}
		}
	}
	if (cstack.empty() == true)
	{
		return true;
	}
	 
    return false;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{

	for (int qnum = 0; qnum < queries.size(); qnum++)
	{
		size_t amount = 0;
		for (int dnum = 0; dnum < data.size(); dnum++)
		{
			if (queries[qnum] == data[dnum])
			{
				amount += 1;
			}
		}
		results.push_back(amount);
	}
}