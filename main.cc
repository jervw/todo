#include "todo.hh"

int main(int argc, char* argv[])
{
    Todo todo;

    if(argc > 1)
    {
        std::vector<std::string> args(argv + 2, argv + argc);
        std::string cmd = argv[1];

        if(cmd=="init")
            todo.init();
        if(cmd=="add")
            todo.add(args);
        if(cmd=="done")
            todo.done(args);
        if(cmd=="sort")
            std::cout << "sort\n";
        if(cmd=="priority")
            todo.priority(args);
        if(cmd=="rm")
            todo.rm(args);
        if(cmd=="clean")
            todo.clean();
        if(cmd=="purge")
            todo.purge();
    }
    else
        todo.list();

    return 0;
}