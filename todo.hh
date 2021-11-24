#pragma once
#include <vector>
#include <string>
#include <iostream>


struct TodoItem {
    std::string text;
    int priority = 0;
    bool state = 0;
};

class Todo {
private:
    const std::string fname = ".todo";
    std::vector<TodoItem> todoList;
    std::vector<int> argsToInt(std::vector<std::string> args);
    void readFile();
    void saveFile();

public:
    Todo();
    void init();
    void list();
    void clean();
    void add(std::vector<std::string> args);
    void rm(std::vector<std::string> args);
    void done(std::vector<std::string> args);
    void priority(std::vector<std::string> args);
    void purge();
    ~Todo();
};
