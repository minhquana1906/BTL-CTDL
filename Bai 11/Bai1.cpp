#include <bits/stdc++.h>
using namespace std;

string transform(const string &word)
{
	string res = word;
	while (!res.empty() && ispunct(res.back()))
	{
		res.pop_back();
	}
	for (char &x : res)
	{
		x = tolower(x);
	}
	return res;
}

class dictionary
{
private:
	set<string> dict;

public:
	// ham doc file
	void readFile(const string &filename)
	{
		ifstream readFile(filename);
		if (!readFile.is_open())
		{
			cout << "Mo file that bai!\n";
			return;
		}
		string word;
		while (getline(readFile, word))
		{
			word = transform(word);
			dict.insert(word);
		}
		readFile.close();
	}
	// ham xuat file
	void exportFile(const string filename)
	{
		ofstream exportFile(filename);
		if (!exportFile.is_open())
		{
			cout << "Mo file that bai!\n";
			return;
		}
		for (auto &it : dict)
		{
			exportFile << it << endl;
		}
		exportFile.close();
	}
	// ham kiem tra chinh ta
	void check()
	{
		cout << "Nhap doan van can kiem tra: \n";
		string text;
		getline(cin, text);
		stringstream ss(text);
		string word;
		int count = 0;
		while (ss >> word)
		{
			word = transform(word);
			if (dict.find(word) == dict.end())
			{
				cout << "- " << word << " sai chinh ta !\n";
				count++;
			}
		}
		if (count == 0)
		{
			cout << "Van ban da nhap khong co tu nao sai chinh ta !\n";
		}
	}
};

int main()
{
	dictionary dic;
	dic.readFile("words.txt");
	dic.check();
	dic.exportFile("outputdic.txt");
	return 0;
}
