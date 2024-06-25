#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_TASKS = 100;

class TaskManager {
private:
    string task_list[MAX_TASKS];
    int num_tasks;
public:
    TaskManager () : num_tasks(0) {}
    void insert_task() {
        if (num_tasks < MAX_TASKS) {
            cout << "Enter the task number " << num_tasks + 1 << ": ";
            getline(cin, task_list[num_tasks]);
            num_tasks += 1;
            cout << endl;
        }
        else {
            cout << "Task list is full. Cannot add more tasks.\n";
        }
    }
    void view_tasks() {
        cout << "\nThe tasks" << endl;
        for (int i = 0; i < num_tasks; ++i) {
            cout << i + 1 << ". " << task_list[i] << endl;
        }
    }
};

void menu() {
    cout << "\nMenu\n"
         << "1. Insert task\n"
         << "2. View tasks\n"
         << "3. Complete task\n"
         << "4. Exit\n"
         << "Enter your choice: ";
}


int main() {
    TaskManager user_task_list;
    int choice = 0;
    while (choice != 4) {
        menu();
        cin >> choice; cout << endl;
        if (choice == 1) {
            user_task_list.insert_task();
        }
        else if (choice == 2) {
            user_task_list.view_tasks();
        }
    }
    return 0;
}