#include <iostream>

#include "MenuByList.h"
#include "QueuePriority.h"

using namespace std;

int main()
{
    const int EXEMPL_SIZE = 10;
    QueuePriority officePrinter(EXEMPL_SIZE);

    MenuByList main_m {
        "Add request",
        "Print document",
        "Show Queue"
    };

    enum
    {
        ADD_Q,
        PRINT_Q,
        SHOW_Q
    };

    while (true)
    {
        switch (main_m.getChoice("What do you want to do?"))
        {
        case ADD_Q: officePrinter.Init(); break;
        case PRINT_Q:
            cout << "Document: " << endl; 
            cout << officePrinter.Extract(); 
            MenuByList::enterPause(); 
            break;

        case SHOW_Q: officePrinter.Show(); MenuByList::enterPause(); break;
        }

        system("cls");
    }
}