
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
	int num;
	int first, second;
	int element;
	cin >> num;
	vector<int> v1;
	vector<int> v2;
	vector<int> v1_tmp;
	vector<int> v2_tmp;
	for (int i = 0; i < num; i++)
	{
		cin >> first >> second;
		v1.clear();
		v2.clear();

		for (int j = 0; j < first; j++)
		{
			cin >> element;
			v1.push_back(element);
		}
		for (int j = 0; j < second; j++)
		{
			cin >> element;
			v2.push_back(element);
		}
		sort(v1.begin(), v1.end());
		v1_tmp.clear();
		v1_tmp.push_back(v1.at(0));
		int j = 0;
		for (int i= 1; i < v1.size() ; i++)
		{
			if (v1.at(i) != v1_tmp.at(j))
			{
				v1_tmp.push_back(v1.at(i));
				j++;
			}

		}
		j = 0;
		sort(v2.begin(), v2.end());
		v2_tmp.clear();
		v2_tmp.push_back(v2.at(0));
		for (int i = 0; i < v2.size(); i++)
		{
			if (v2.at(i) != v2_tmp.at(j))
			{
				v2_tmp.push_back(v2.at(i));
				j++;
			}
		}
		vector<int> v3;
		int idx = 0;
		for (int k = 0; k < v1_tmp.size(); k++)
		{
			//v1의 값이 v2보다 작다면 넣기
			if (v1_tmp.at(k) < v2_tmp.at(idx))
			{
				v3.push_back(v1_tmp.at(k));
			}
			//v1의 값이 v2와 같다면 v2 다음 인덱스로 보내고 넣기
			else if (v1_tmp.at(k) == v2_tmp.at(idx))
			{
				v3.push_back(v1_tmp.at(k));
				idx++;
			}
			else //v1값이 v2보다 크다면 넘기기
			{
				while (idx < v2_tmp.size() &&v2_tmp.at(idx) <= v1_tmp.at(k))
				{
					v3.push_back(v2_tmp.at(idx));
					idx++;
				}
				if(v1_tmp.at(k)!=v2_tmp.at(idx-1))
					v3.push_back(v1_tmp.at(k));
			}
		}
		if (idx < v2_tmp.size() - 1)
		{
			for (int i = idx; i < v2_tmp.size(); i++)
			{
				v3.push_back(v2_tmp.at(idx));
			}
		}

		cout << v3.size() << endl;
	}
	return 0;

}

