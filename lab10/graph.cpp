#include "graph.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>

using namespace std;


bool DFS(Node* start, Node* end) {
	stack<Node*> stk;
	set<Node*> disc;
	stk.push(start);
	while(!stk.empty()){
		Node* cur = stk.top();
		stk.pop();
		disc.insert(cur);
		for(Node* n: cur->neighbors){
			if(n == end) {
				return true;
			} else if(disc.find(n) == disc.end()){
				stk.push(n);
			}
		}
	}
	return false;
}

bool BFS(vector<vector<int> > adjacency_matrix, int start, int end) {
	queue<int> q;
	set<int> disc;
	q.push(start);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		disc.insert(cur);
		for(int i = 0; (unsigned)i < adjacency_matrix[cur].size(); i++){
			if(adjacency_matrix[cur][i] == 1 && i == end){
				return true;
			} else if (disc.find(i) == disc.end() && adjacency_matrix[cur][i] == 1){
				q.push(i);
			}
		}
	}
	return false;
}