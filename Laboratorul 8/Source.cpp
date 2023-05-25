#include <fstream>
#include <string>
#include <map>
#include <queue>
#include<iostream>
using namespace std;
ifstream fin("input.txt");

class Compare {
public:
	bool operator() (pair<string, int> p1, pair<string, int> p2) {
		if (p1.second < p2.second)
			return false;
		if (p1.second > p2.second)
			return true;
		if (p1.first < p2.first)
			return true;
		return false;
	}
};

int main()
{
	map<string, int>Fraza;
	string Cuvant;
	string Prop;
	string Sep = " ,.!?";
	int incp = 0, sf = 0;

	getline(fin, Prop);
	for (int i = 0; i < Prop.size(); i++)
		Prop[i] = tolower(Prop[i]);

	while (Prop.size() > 1)
	{
		incp = Prop.find_first_not_of(Sep);
		sf = Prop.find_first_of(Sep);
		Cuvant = Prop.substr(incp, sf);
		Prop = Prop.substr(incp);
		Prop = Prop.substr(sf);
		if (Cuvant != "")
			Fraza[Cuvant]++;
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> Coada;
	for (auto it = Fraza.begin(); it != Fraza.end(); it++)
	{
		Coada.push(pair<string, int>(it->first, it->second));
	}

	while (!Coada.empty())
	{
		cout << Coada.top().first << "->" << Coada.top().second << endl;
		Coada.pop();
	}
}