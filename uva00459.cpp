#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
//Graph Connectivity

using namespace std;

void distribute_group(vector<int>& groups)
{
	for(unsigned int i=0; i < groups.size(); ++i)
		groups[i] = i;
}
void associate_the_group(vector<int>& groups, int num_1, int num_2, int& group)
{	//convert all the bigger group to the smaller group
	for(unsigned int i=0; i < groups.size(); ++i)
	{
		if(groups[i] == num_2)
			groups[i] = num_1;
	}
	--group;
}
void group_union(vector<int>& groups, int member_1, int member_2, int& group)
{
	if(groups[member_1] > groups[member_2])
	{	
		associate_the_group(groups, groups[member_2], groups[member_1], group);
	}
	else if(groups[member_1] < groups[member_2])
	{	
		associate_the_group(groups, groups[member_1], groups[member_2], group);
	}
}

int main()
{
	char G;
	int n;
	cin >> n;
	
	while(n--)
	{	
		cin >> G, cin.get();
		int group = G - 'A' + 1; // the number of max
		vector<int> groups(G-'A'+1);
		string node;

		distribute_group(groups);
		
		while(getline(cin, node))
		{
			if(node == "") break;
			// A is the first group, B is the second, and so on...
			group_union(groups, node[0]-'A', node[1]-'A', group);	
		}

		cout << group << endl;
		if(n > 0)
			cout << endl;	
	}

	return 0;
}