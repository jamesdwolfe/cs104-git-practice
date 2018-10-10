#include "AllCombos.h"
#include <iostream>

using namespace std;

//you may write any helper functions you need

void AllCombosHelper(vector<string>& result, string input, int k, string segment){
	if(k == 0){
		result.push_back(segment);
		cout << segment << endl;
		return;
	}

	for(unsigned int i = 0; i < input.size(); i++){
		string temp = segment;
		temp += input[i];
		AllCombosHelper(result,input,k-1,temp);
	}

}

void AllCombos(vector<string>& result, string input, int k){
	AllCombosHelper(result,input,k,"");
}
