#pragma once
#include <vector>
#include <string>
#include <iostream>


struct TodoItem {
    std::string s;
};

class Todo {
private:
    const std::string fname = ".todo";
    std::vector<TodoItem> todoList;

public:
    Todo();
    void readFile();
    void saveFile();
    void init();
    void list();
    void add(std::vector<std::string> args);
    void rm(std::vector<std::string> args);
    ~Todo();
};
