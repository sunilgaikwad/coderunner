#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a;
	a.push_back(1);a.push_back(3);a.push_back(8);a.push_back(9);a.push_back(11);a.push_back(12);

	vector<int> b;
	b.push_back(3);b.push_back(4);b.push_back(9);b.push_back(12);b.push_back(18);

	std::vector<int> result;

	int aSize = a.size();
	int bSize = b.size();
	int i = 0;
	int j = 0;
	while((i < aSize) && (j < bSize))
	{
		if(a[i] == b[j])
		{
			result.push_back(a[i]);
			i++;
			j++;
		}
		else if(a[i] < b[j])
		{
			while(a[i] < b[j])
				i++;
		}
		else
		{
			while(b[j] < a[i])
				j++;
		}
	}

	for(int k = 0; k < result.size(); k++)
		cout<<result[k]<<endl;
}