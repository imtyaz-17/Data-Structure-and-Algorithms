// Check for Balanced Brackets in an expression (well-formedness) using Stack
// https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/

// using Stack:
// Time Complexity: O(N) , Auxiliary Space: O(N).

#include <bits/stdc++.h>
using namespace std;

bool areBracketsBalanced(string expr)
{
    stack<char> temp;
    for (int i = 0; i < expr.length(); i++)
    {
        if (temp.empty())
        {
            temp.push(expr[i]);
        }
        else if ((temp.top() == '(' && expr[i] == ')') || (temp.top() == '{' && expr[i] == '}') || (temp.top() == '[' && expr[i] == ']'))
        {
            temp.pop();
        }
        else{
            temp.push(expr[i]);
        }
    }

    if (temp.empty()) {
        return true;
    }
    return false;
}
int main()
{
    string expr = "{()}[]";

    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}