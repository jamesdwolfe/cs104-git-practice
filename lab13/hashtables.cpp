#include "hashtables.h"

#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <unordered_map>

using namespace std;

//case does not matter
//ignore special characters ie. only consider letters a-z

bool isAnagram(std::string s, std::string t) {
	unordered_map<char, int> m;
	for(size_t i = 0; i < s.size(); i++){
		if(isalnum(s[i])){
			m[tolower(s[i])]+=1;
		}
	}
	for(size_t i = 0; i < t.size(); i++){
		if(m[tolower(t[i])] > 0){
			m[tolower(t[i])]--;
		} else if (isalnum(t[i])){
			return false;
		}
	}

	for(pair<char,int> x: m){
		if (x.second != 0) return false;
	}
    return true;
}

//output FIRST pair found

pair<int, int> twoSum(vector<int> input, int target) {
	unordered_map<int,int> m;
	for(size_t i = 0; i < input.size(); i++){
		int minus = target - input[i];
		if(m[minus] != 0){ return make_pair(m[minus]-1,i); } 
		else { m[input[i]] = i+1; }
	}
    return make_pair(-1, -1);
}