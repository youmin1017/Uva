#include <iostream>
#include <string>
#include <vector>
//Automated Judge Script

using namespace std;

int str_cmp(string solution, string answer, int result)
{
	string::iterator it1, it2;
	it1 = solution.begin(), it2 = answer.begin();

	for( ; it1 != solution.end() || it2 != answer.end(); ++it1, ++it2)
	{
		while(isspace(*it1) && it1 != solution.end()) ++it1;
		while(isspace(*it2) && it2 != answer.end())   ++it2;
		
		if(*it1 == *it2)
			continue;
		else
			return 0;
	}
	if(solution.size() == answer.size()) return result;
	else                                 return -1;
}


int main()
{
	int n, m;

	for(int count=1; cin >> n && n; ++count)
	{
		cin.get();

		int result = 1;
		vector<string> solution(n);
		for(int i=0; i < n; ++i)
			getline(cin, solution[i]);

		cin >> m, cin.get();
		vector<string> answer(m);
		for(int i=0; i < m; ++i)
			getline(cin, answer[i]);

		for(int i=0; i < m; ++i)
		{
			if(i < n) 
			{
				result = str_cmp(solution[i], answer[i], result);

				if(result == 0)
					break;
				else 
					continue;
			}
			else
			{
				for(auto x: answer[i])
				{
					if(isprint(x))
					{
						result = 0;
						break;
					}
					else if(result == 1)
						result = -1;
				}
			}
		}
		cout << "Run #" << count << ": ";
		if(result == 1)      cout << "Accepted\n";
		else if(result == 0) cout << "Wrong Answer\n";
		else                 cout << "Presentation Error\n";
	}
	
	return 0;
}