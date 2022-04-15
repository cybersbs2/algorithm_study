#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string, int);
int solution(string);

#pragma optimize("", off)
int solution(string s) {
	int answer = 0;
	int min = 1000000;

	for (int x = 1; x <= s.size(); x++)
	{
		string ans = "";
		// i : 자를 문자열 길이
		auto s_arr = split(s, x);

		if (s_arr.size() == 0) continue;

		int i = 0;
		int j = 1;

		while ((i != j) && (j <= s_arr.size() - 1))
		{
			if (s_arr[i] == s_arr[j])
			{
				// 문자 합칠 수 있음
				j++;
			}
			else
			{
				// 문자 합칠 수 없음
				if ((j - i) == 1)
				{
					// 1은 생략
					ans = ans + s_arr[i];
				}
				else
				{
					// 1 이외
					ans = ans + to_string(j - i) + s_arr[i];
				}
				i = j;
				j++;
			}
		}

		if ((j - i) == 1)
		{
			// 1은 생략
			ans = ans + s_arr[i];
		}
		else
		{
			// 1 이외
			ans = ans + to_string(j - i) + s_arr[i];
		}

		min = (min > ans.size() ? ans.size() : min);
	}
	answer = min;
	return answer;
}



vector<string> split(string input, int x) {
	vector<string> answer;

	string temp = input;

	while (temp.size() != 0)
	{
		if (temp.size() < x)
		{
			answer.push_back(temp);
			return answer;
		}
		string buf = temp.substr(0, x);
		temp = temp.substr(x, temp.size() - x);
		answer.push_back(buf);
	}

	return answer;
}
