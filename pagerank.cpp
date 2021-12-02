#include<bits/stdc++.h>
#include<map>
#include<vector>
#include<iostream>

using namespace std;

vector<int> getOutLinks(map<int, vector<int> > &ad, int n) {
	vector<int> ans;
	for(int i=0; i<n; i++) {
		int count = 0;
		for(int j=0; j<ad[i].size(); j++) {
			if(ad[i][j] == 1)
				count++;
		}
		ans.push_back(count);
	}
	return ans;
}
void convertToInlinks(map<int, vector<int> > &adjacency, int nodes) {
	for(int i=0; i<nodes; i++) {
		for(int j=0; j<i; j++) {
			int temp = adjacency[i][j];
			adjacency[i][j] = adjacency[j][i];
			adjacency[j][i] = temp;
		}
	}
}
void print(map<int, vector<int> > &adjacency, int nodes) {
	/*for(auto i : adjacency) {
		for(auto j : i.second) {
			cout << j << " ";
		}
	}*/
	for(int i=0; i<nodes; i++) {
		for(int j=0; j<nodes; j++) {
			cout << adjacency[i][j] << " ";
		}
		cout << endl;
	}
}
void print(vector<float> p, int it) {
	cout << "The Page Ranks in the iteration " << it << " are :" << endl;
	for(int i=0; i<p.size(); i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}
int main() {
	map<int, vector<int> > adjacency;
	int nodes;
	float d;
	cout << "Enter the number of nodes and damping factor" << endl;
	cin >> nodes;
	cin >> d;
	cout << "Enter the graph data" << endl;
	for(int i=0; i<nodes; i++) {
		vector<int> temp;
		for(int j=0; j<nodes; j++) {
			int data;
			cin >> data;
			temp.push_back(data);
		}
		adjacency[i] = temp;
	}
	vector<int> outlinks = getOutLinks(adjacency, nodes);
	convertToInlinks(adjacency, nodes);
	vector<float> page_rank;
	for(int i=0; i<nodes; i++) {
		page_rank.push_back(1.0);
	}
	cout << "Enter the number of iterations" << endl;
	int it, count;
	cin >> it;
	while(it-->0) {
		vector<float> temp;
		for(int i=0; i<nodes; i++) {
			float a = 0;
			for(int j=0; j<nodes; j++) {
				if(adjacency[i][j] == 1) {
					a = a + page_rank[j]/(float)outlinks[j];
				}
			}
			a = a*d;
			a = a+(1-d);
			temp.push_back(a);
		}
		page_rank = temp;
		print(page_rank, ++count);
	}
	return 0;
}
