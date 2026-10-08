#include<iostream>
#include<queue>
#include<string>

using namespace std;

queue<string> studQueue;

void addStudent(string name)
{
    studQueue.push(name);
    cout << name << " Added to the queue" << endl;
}

void serveStudent()
{
    if (studQueue.empty())
    {
        cout << "Queue is empty, No students to be served" << endl;
    } else
    {
        cout << "Served: " << studQueue.front() << endl;
        studQueue.pop();
    }
}

void displayQueue()
{
    if (studQueue.empty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Waiting students: " << endl;
    queue<string> temp = studQueue;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    cout << "========================================" << endl;
    addStudent("Vishal");
    addStudent("Ashley");
    addStudent("Sandy");
    addStudent("Anand");
    addStudent("Nithya");

    cout << "========================================" << endl;
    displayQueue();

    cout << "========================================" << endl;
    serveStudent();
    serveStudent();

    cout << "========================================" << endl;
    displayQueue();

    cout << "========================================" << endl;
    serveStudent();
    serveStudent();

    cout << "========================================" << endl;

    return 0;
}
