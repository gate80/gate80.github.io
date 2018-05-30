#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <fstream>
#include <time.h>

// test
#include<cstdlib>


using namespace std;
int max(int a, int b)
{
	return ((a < b) ? b : a);
}
struct v
{
	string str;
	string answer;
	size_t str_hash;
	void set_answer(string t) { answer = t; }
	void set_str(string t)
	{
		str = t;
	}
	string getstr()
	{
		return str;
	}
	void strhash()
	{
		hash<string> hash_fn; size_t str_hash = hash_fn(str);
	}

	/// checker
	bool vec() // G A T E | GATE (split)
	{
		vector <char> vanswer;
		vector <char> vstr;
		for (char c : answer)
			if (c != ' ')vanswer.push_back(c);
		for (char c : str)
			if (c != ' ')vstr.push_back(c);

		for (int i = 0; i<max(vstr.size(), vanswer.size()); i++)
			if (vstr[i] != vanswer[i])
			{
				return false;
			}
		return true;
	}
	bool str1() // GATE | GATE
	{
		return ((str == answer) ? true : false);
	}
	bool test()
	{
		return true;
	}
};

void del_endl(string &s) // string test\n -> test
{
	s =  s.substr(0, s.size() - 1);
}
int main(int argc, char *argv[])
{
	v v;
	
	ifstream property("0001/property.txt", ios::in); // настройки задачи
	ofstream log("log.txt", ios::out); // log
	log << argv[0];

	int SIZET;
	string infile, OUTfille;
	property >> SIZET >> infile >> OUTfille;
	// time
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	log << asctime(timeinfo);

	log << "{test№;input;trueanswer;answer;true/false}\n";


		for (int i = 1; i <= SIZET; i++)
		{
			
			ifstream TestOut(("0001/output/" + to_string(i) + ".txt"), ios::in); // output ответа правильного
			ifstream TestIn(("0001/input/" + to_string(i) + ".txt"), ios::in); // input для теста
			ifstream output("0/" + OUTfille, ios::in); // ответ
			fstream input("0/" + infile, ios::out); // input
			string tmp, sout = "", sin = "", soutput = "";
			// scan
			while (getline(TestOut, tmp))
				sout += tmp + "\n";
			while (getline(TestIn, tmp))
				sin += tmp + "\n";
			input << sin;

			system("start C:\\Users\\Иван\\Desktop\\gate7.0\\gate7.0\\0\\t.exe");
			// run
			while (getline(output, tmp))
				soutput += tmp + "\n";

			// delete \n
			del_endl(sin);
			del_endl(sout);
			del_endl(soutput);


			log << i << ";" << sin << ";" << sout << ";" << soutput << ";test\n";

			/////////////// close filles
			TestOut.close();
			TestIn.close();
			output.close();
			input.close();
			///////////////
		}
	
		//test run failed  failed lol 
		printf("%s\n", argv[0]);
		system("pause");
	return 0;
}