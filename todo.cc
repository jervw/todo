#include "todo.hh"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

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
    std::string ftext;
    int fpriority;
    bool fstate;

    while(f >> ftext >> fpriority >> fstate)
    {
        TodoItem item;
        item.text = ftext;
        item.priority = fpriority;
        item.state = fstate;
        todoList.push_back(item);
    }
    f.close();
}

void Todo::saveFile()
{
    std::fstream f(fname, std::ios::out | std::ios::trunc);
    for(auto i : todoList)
        f << i.text << " " << i.priority << " " << i.state << "\n";
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
    for(int i = 1; i <= todoList.size(); ++i)
    {
        std::cout << "\e[1m" << i << "\e[0m ";
        std::string text = todoList[i-1].text;
        std::string s = (todoList[i-1].state) ? "\u2713 " + todoList[i-1].text  : "\u2717 " + todoList[i-1].text;
        std::cout << s << "\n";
    }

}

void Todo::add(std::vector<std::string> args)
{
    for(auto i : args)
    {
        TodoItem item;
        item.text = i;
        todoList.push_back(item);
    }
}

// TODO Check if num in range
void Todo::rm(std::vector<std::string> args)
{
    std::vector<int> nums = argsToInt(args);

    for(auto j : nums)
        todoList.erase(todoList.begin() + j-1);
}

// TODO Check if num in range
void Todo::done(std::vector<std::string> args)
{
    std::vector<int> nums = argsToInt(args);

    for(auto j : nums)
        todoList[j-1].state = 1;

}

void Todo::priority(std::vector<std::string> args)
{
    std::vector<int> nums = argsToInt(args);
    todoList[nums[0]-1].priority = nums[1];
}

void Todo::clean()
{
    for(int x = 0; x <= todoList.size(); ++x)
        if(todoList[x].state)
            todoList.erase(todoList.begin() + x);
}


std::vector<int> Todo::argsToInt(std::vector<std::string> args)
{
    std::vector<int> nums;
    std::transform(args.begin(), args.end(), std::back_inserter(nums),
        [](const std::string& str) { return std::stoi(str); });

    return nums;
}

void Todo::purge() { todoList.clear(); }
