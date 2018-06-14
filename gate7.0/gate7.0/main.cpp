#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> // cout
#include <string>   // string
#include <vector>   // vector
#include <fstream>	// fille >> <<
#include <sstream>	// ostringstream
#include <time.h>	// time
using namespace std;
void run(string command)
{
	system(command.c_str());
}
class LXC {
private:
	string os;
	string container;
public:
	LXC(string container_, string os_)
	{
		container = container_;
		os = os_;
	}
	void installPackage()
	{
		run("sudo apt-get install lxc");
	}
	void create_container(string dist, string relese, string arch)
	{
		run(" lxc-create -t download -n " + container + " -- --dist " + dist + " --release " + relese + " --arch " + arch);
	}
	void start_container()
	{
		run("sudo lxc-start " + container);
	}
	void ls_container() // list box
	{
		run("sudo lxc-ls");
	}
	void info_container() //Подробная информация о контейнер
	{
		run("sudo lxc-info" + container);
	}
	void stop_container() // остоновка контейнера
	{
		run("sudo lxc-stop " + container);
	}
	void copy_container(string copy_name) // Создание клона контейнера (test-container должен быть остановлен): fix bag
	{
		run("sudo lxc-copy" + container + " -N" + copy_name);
	}
	void del_container()
	{
		run("sudo lxc-destroy " + container);
	}
	void freeze_container()
	{
		run("sudo lxc-freeze " + container);
	}
	void unfreeze_container()
	{
		run("sudo lxc-unfreeze " + container);
	}
	void memory_limit(int M)
	{
		run("sudo lxc-cgroup -n " + container + " memory.limit_in_bytes " + to_string(M) + "M");
	}
};
class v
{
private:
	string str, answer;
public:
	v(string answer_, string str_)
	{
		str = str_;
		answer = answer_;
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
		if (vstr.size() != vanswer.size())
			return false;
		for (int i = 0; i < vstr.size(); i++)
			if (vstr[i] != vanswer[i])
				return false;
		return true;
	}
	bool str1() // GATE | GATE
	{
		return ((str == answer) ? true : false);
	}
	bool str1_() // GATE_ | GATE
	{
		return ((str == answer + " " || str == answer) ? true : false);
	}
	bool no() // no fix a+n 1 || 1!=1
	{
		return ((str != answer && str != answer + " ") ? true : false);
	}
};

void readFile(string fileName, string &str)
{
	std::ifstream in(fileName.c_str(), std::ios::binary);
	ostringstream out;
	str.clear();
	out << in.rdbuf();
	out.str().swap(str);
}
int main(int argc, char *argv[])
{
	clock_t time;

	time = clock();
	ifstream property("0001/property.txt", ios::in); // настройки задачи
	ofstream log("log.txt", ios::out); // log
	log << argv[0];

	int SIZET;
	string infile, OUTfille;
	property >> SIZET >> infile >> OUTfille;
	// time

	log << "\n{test;input;trueanswer;answer;true/false}\n";
	for (int i = 1; i <= SIZET; i++)
	{
		string testout, testin, output;
		fstream input("0/" + infile, ios::out);							// input
		readFile(("0001/output/" + to_string(i) + ".txt"), testout);	// output ответа правильного
		readFile(("0001/input/" + to_string(i) + ".txt"), testin);		// input для теста
		readFile(("0/" + OUTfille), output);							// ответ
		input << testin;

		v(testout, output);
		log << i << ";" << testin << ";" << testout << ";" << output << ";" << "\n";
		/////////////// close filles
		input.close();
		///////////////
	}

	// test polygon

	time = clock() - time;
	log << (double)time / CLOCKS_PER_SEC;
	return 0;
}