/*
MIT License

Copyright (c) 2024 CodeAlpha

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/    
#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;

class TaskManager {
private:
    string task_list[MAX_TASKS];
    bool completed[MAX_TASKS];
    int num_tasks;
public:
    TaskManager() : num_tasks(0) {
        for (int i = 0; i < MAX_TASKS; i++) {
            completed[i] = false;
        }
    }

    void insert_task() {
        if (num_tasks < MAX_TASKS) {
            cin.ignore();
            cout << "Enter task " << num_tasks + 1 << ": ";
            getline(cin, task_list[num_tasks]);
            num_tasks++;
            cout << endl;
        }
        else {
            cout << "Task list is full. Cannot add more tasks.\n";
        }
    }

    void view_tasks() {
        cout << "\nTasks:" << endl;
        for (int i = 0; i < num_tasks; ++i) {
            cout << i + 1 << ". " << task_list[i]
                << (completed[i] ? " [Completed]" : "") << endl;
        }
    }

    void complete_task() {
        int task_num;
        cout << "Enter task number to mark as completed: ";
        cin >> task_num;
        if (task_num > 0 && task_num <= num_tasks) {
            completed[task_num - 1] = true;
            cout << "Task " << task_num << " marked as completed." << endl;
        }
        else {
            cout << "Invalid task number." << endl;
        }
    }

    void remove_task() {
        int task_number;
        cout << "Enter task number to remove: ";
        cin >> task_number;
        if (task_number > 0 && task_number <= num_tasks) {
            for (int i = task_number - 1; i < num_tasks - 1; ++i) {
                task_list[i] = task_list[i + 1];
                completed[i] = completed[i + 1];
            }
            task_list[num_tasks - 1].clear();
            completed[num_tasks - 1] = false;
            num_tasks--;
            cout << "Task " << task_number << " removed." << endl;
        }
        else {
            cout << "Invalid task number." << endl;
        }
    }
};

void menu() {
    cout << "\nMenu\n"
        << "1. Insert task\n"
        << "2. View tasks\n"
        << "3. Complete task\n"
        << "4. Remove task\n"
        << "5. Exit\n"
        << "Enter your choice: ";
}

int main() {
    TaskManager user_task_list;
    int choice = 5;
    do {
        menu();
        cin >> choice; cout << endl;
        switch (choice) {
        case 1:
            user_task_list.insert_task();
            break;
        case 2:
            user_task_list.view_tasks();
            break;
        case 3:
            user_task_list.complete_task();
            break;
        case 4:
            user_task_list.remove_task();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
