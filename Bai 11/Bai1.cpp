#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <sstream>
#include <cctype>
using namespace std;

using ll = long long;

string transform(const string &word){
	string res = word;
	while(!res.empty() && ispunct(res.back())){
		res.pop_back();
	}
	for(char &x:res){
		x = tolower(x);
	}
	return res;
}

class dictionary{
	private:
		set<string>s;
	public:
		void readFile(const string& filename){
			ifstream readFile(filename);
			if(!readFile.is_open()) {
				cout<<"Mo file that bai!\n";
				return ;
			}
               string word;
			while(getline(readFile,word)) {
			   	word = transform(word);
			   	s.insert(word);
			}
			// for(auto& it:s){
			// 	cout<<it<<endl;
			// }
			readFile.close();   
		}
		 void exportFile(const string filename){
		 	ofstream exportFile(filename);
		 	if(!exportFile.is_open()){
		 		cout<<"Mo file that bai!\n";
		 		return ;
		 	}
				for(auto &it:s){
					exportFile << it << endl;
				}
				exportFile.close();
		 }
		void check() {
			string text;
			getline(cin,text);
			stringstream ss(text);
			string word;
			int count=0;
			while(ss >> word){
				word=transform(word);
				if(s.find(word) == s.end()){	
					cout<<"- "<<word<<" sai chinh ta !\n";
					count++;
				}
			}
			if(count==0){
				cout<<"Van ban da nhap khong co tu nao sai chinh ta !\n";
			}
		}
};

int main()
{
	dictionary dic;
	dic.readFile("words.txt");
	dic.check();
	//dic.exportFile("outputdic.txt");
	return 0;
}
