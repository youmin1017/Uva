#include <iostream>
#include <string>
#include <vector>
//Automated Judge Script

using namespace std;

int main()
{
	int n, m;
	string sol, ans;

	for(int count=1; cin >> n && n; ++count)
	{
		cin.get();
		sol = "", ans = "";
		
		vector<string> solution(n);

		for(int i=0; i < n; ++i)
		{
			getline(cin, solution[i]);
			for(char x: solution[i])
				if(isdigit(x))
					sol += x;
		}

		cin >> m, cin.get();
		vector<string> answer(m);

		for(int i=0; i < m; ++i)
		{
			getline(cin, answer[i]);
			for(char x: answer[i])
				if(isdigit(x))
					ans += x;
		}

		cout << "Run #" << count << ": ";

		if(sol == ans)
			if(solution == answer)
				cout << "Accepted\n";
			else
				cout << "Presentation Error\n";
		else
			cout << "Wrong Answer\n";
	}
	
	return 0;
}