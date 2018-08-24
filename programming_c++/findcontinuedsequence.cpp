#include <iostream>
#include <string>
using namespace std;


int IsSequence(string input, int length)
{
	int itlen = length/2;
	int comparelen = 1;
	while(itlen >= 1)
	{
		string str1 = input.substr(0, comparelen);
		string str2 = input.substr(comparelen, comparelen);
		cout<<str1<<" "<<str2<<endl;
		if(str1.compare(str2) == 0)
		{
			return comparelen;
		}
		comparelen++;
		itlen--;
	}
	cout<<endl;
	return 0;
}

int main()
{
	string input = "abcdcd";

	int length = input.length();
	bool isvalid = true;
	for(int i = 0; i < (length - 1); i++)
	{
		string substr = input.substr(i, length - i);
		cout<<substr<<endl;
		int index = IsSequence(substr, (length - i));
		if(index != 0)
		{
			cout<<input<<" has repeated sequence starting at "<< i + index<<endl;
		 	break;
		}
	}
}