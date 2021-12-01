#include "todo.hh"

int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        Todo todo(argc, argv);
        std::string cmd = argv[1];

        if(cmd=="add")
            todo.add();
        if(cmd=="list" || cmd=="ls")
            todo.list();
        if(cmd=="done")
            todo.done();
        if(cmd=="sort")
            std::cout << "sort\n";
        if(cmd=="rm")
            todo.rm();
        if(cmd=="clean")
            todo.clean();
        if(cmd=="purge")
            todo.purge();
        if(cmd=="help" || cmd=="--help" || cmd=="-h")
            todo.usage();
    }
    else
        std::cout << "Type 'todo help' for the list of commands.\n";

    return 0;
}