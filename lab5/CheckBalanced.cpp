#include "CheckBalanced.h"
#include <stack>

using namespace std;

bool CheckBalancedParentheses(std::string input) {
    stack<char> stk;
    //Finish The Function :D
    for(char& c : input) {
    	if(c == '('){
    		stk.push(c);
    	} else if (c == ')'){
    		if(stk.empty()) { return false; }
    		stk.pop();
    	}
	}
	if(!stk.empty()) { return false; }
    return true;
}

bool CheckBalancedAll(std::string input) {
    stack<char> stk;
    //Finish The Function :D
    for(char& c : input) {
    	if(c == '(' || c == '[' || c == '{'){
    		stk.push(c);
    	} else if (c == ')'){
    		if(stk.empty() || stk.top() == '{' || stk.top() == '[') { return false; }
    		stk.pop();
    	} else if (c == ']'){
			if(stk.empty() || stk.top() == '{' || stk.top() == '(') { return false; }
    		stk.pop();
    	} else if (c == '}'){
			if(stk.empty() || stk.top() == '(' || stk.top() == '[') { return false; }
    		stk.pop();
    	}
	}
	if(!stk.empty()) { return false; }
    return true;
}
