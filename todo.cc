#include "todo.hh"
#include <fstream>
#include <stdexcept>

struct TodoItem todoItem;

Todo::Todo()
{
    readFile();
}

Todo::~Todo()
{
    saveFile();
}

// TODO if file doesnt exists, throw error
void Todo::readFile()
{
    std::ifstream f(fname);
    for(std::string line; getline(f, line); )
    {
        TodoItem item;
        item.s = line;
        todoList.push_back(item);
    }
    f.close();
}

void Todo::saveFile()
{
    std::fstream f(fname, std::ios::out | std::ios::trunc);
    for(auto i : todoList)
        f << i.s + "\n";
    f.close();
}

void Todo::init()
{
    std::ofstream f(fname);

    if(!f.good())
        std::cout << "Done!\n";
    else
        std::cout << "Already initialized!\n";
    f.close();
}

void Todo::list()
{
    for(int i = 1; i < todoList.size()+1; ++i)
        std::cout << "\e[1m" << i << "\e[0m " << todoList[i-1].s << std::endl;
}

void Todo::add(std::vector<std::string> args)
{
    for(auto i : args)
    {
        TodoItem item;
        item.s = i;
        todoList.push_back(item);
    }
}

void Todo::rm(std::vector<std::string> args)
{
    std::vector<int> nums;
    for(auto i : args) {
        try {
            nums.push_back(std::stoi(i));
        }
        catch(std::invalid_argument& e) {
            continue;
        }
    }

    for(auto j : nums) {
        todoList.erase(todoList.begin() + j-1);
    }
}

