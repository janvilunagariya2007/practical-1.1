
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main()
{
    string exp;
    stack<int> st;

    cout << "Enter postfix expression (single digit operands): ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++)
    {
        if (isdigit(exp[i]))
        {
            st.push(exp[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();

            int op1 = st.top();
            st.pop();

            switch (exp[i])
            {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
            }
        }
    }

    cout << "Result = " << st.top();

    return 0;
}