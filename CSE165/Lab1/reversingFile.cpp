#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream myfile("code.cpp");

	string myline;

	vector<string> myvector;

	while (getline(myfile, myline)) {
		myvector.push_back(myline);
	}

	for (int i = myvector.size(); i > -1; i--) {
		cout << myvector[i] << endl;
	}
		
	return 0;
}