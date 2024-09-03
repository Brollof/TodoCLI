#include <iostream>
#include <string>
#include <vector>
#include "CLI11.hpp"
#include "rapidcsv/src/rapidcsv.h"

using namespace std;

#define CSV_FILENAME "todo.csv"

struct Data
{
	uint32_t id;
	string task;
	int created;
	bool done;
};

class Storer
{
public:
	virtual bool Save() = 0;
	virtual bool Load() = 0;
	virtual ~Storer() {};

private:
	vector<Data> tasks;
};

class CSVFile : public Storer
{
public:
	CSVFile() : m_filename(CSV_FILENAME)
	{
		cout << "csv file: " << m_filename << endl;
	}

	bool Save() override
	{
		return true;
	}

	bool Load() override
	{
		return true;
	}
private:
	string m_filename;
};

int main(int argc, char** argv)
{
	CLI::App app{"App description"};

	string tmp = "";
	uint32_t num = -1;

	CLI::App *add = app.add_subcommand("add", "add a new task");
	add->add_option("task", tmp)->required();

	CLI::App *list = app.add_subcommand("list", "show undone tasks");
	list->add_flag("--all", "show all tasks");

	CLI::App *complete = app.add_subcommand("complete", "complete task");
	complete->add_option("ID", num, "task ID")->required();

    CLI11_PARSE(app, argc, argv);

	CSVFile csv;

	return 0;
}

