#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

char computeGrade(float avg)
{
    if (avg >= 90) {
        return 'A';
    } else if (avg >= 80) {
        return 'B';
    } else if (avg >= 70) {
        return 'C';
    } else if (avg >= 60) {
        return 'D';
    } else if (avg >= 50) {
        return 'E';
    } else {
        return 'F';
    }
}
class Student
{
public:
    int rollNumber;
    string name;
    float marks[5];
    float avg;
    void calculateAverage()
    {
        float total = 0;
        for (int i = 0; i < 5; i++)
        {
            total = total + marks[i];
        }
        avg = total / 5.0;
    }
};
bool compareStudents(const Student& a, const Student& b)
{
    return a.avg > b.avg;
}
int main()
{
    Student students[50];
    int studentsCount = 0;
    int choice;
    while (true)
        {
        cout << "\n===== Student Grades =====\n";
        cout << "1. Add  2. Display by Roll No  3. Topper  4. Display All  5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                if (studentsCount >= 50)
                {
                    cout << "Class is full (50 students max).\n";
                    break;
                }
                int roll;
                cout << "Roll No: ";
                cin >> roll;
                bool exists = false;
                for (int i = 0; i < studentsCount; i++)
                {
                    if (students[i].rollNumber == roll)
                    {
                        exists = true;
                        break;
                    }
                }
                if (exists)
                {
                    cout << "Roll number already exists.\n";
                    break;
                }
                students[studentsCount].rollNumber = roll;
                cout << "Name: ";
                cin.ignore();
                getline(cin, students[studentsCount].name);
                cout << "Marks (5 subjects): ";
                for (int i = 0; i < 5; i++)
                {
                    cin >> students[studentsCount].marks[i];
                }
                students[studentsCount].calculateAverage();
                studentsCount++;
                cout << "Student added.\n";
                break;
            }
            case 2:
            {
                int roll;
                cout << "Enter Roll No: ";
                cin >> roll;
                bool found = false;
                for (int i = 0; i < studentsCount; i++)
                    {
                    if (students[i].rollNumber == roll)
                    {
                        cout << students[i].name
                             << " - Average: " << fixed << setprecision(2) << students[i].avg
                             << " - Grade: " << computeGrade(students[i].avg) << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 3:
            {
                if (studentsCount == 0)
                {
                    cout << "No students available.\n";
                    break;
                }
                float maxAverage = students[0].avg;
                for (int i = 1; i < studentsCount; i++)
                {
                    if (students[i].avg > maxAverage)
                    {
                        maxAverage = students[i].avg;
                    }
                }
                cout << "Topper(s):\n";
                for (int i = 0; i < studentsCount; i++)
                {
                    if (students[i].avg == maxAverage)
                    {
                        cout << students[i].name
                             << " (" << fixed << setprecision(2) << students[i].avg << ")\n";
                    }
                }
                break;
            }
            case 4:
            {
                if (studentsCount == 0)
                {
                    cout << "No students available.\n";
                    break;
                }
                Student sortedStudents[50];
                for (int i = 0; i < studentsCount; i++)
                {
                    sortedStudents[i] = students[i];
                }
                stable_sort(sortedStudents, sortedStudents + studentsCount, compareStudents);

                cout << "\n--- All Students ---\n";
                for (int i = 0; i < studentsCount; i++)
                {
                    cout << "Roll: " << sortedStudents[i].rollNumber
                         << " | Name: " << sortedStudents[i].name
                         << " | Average: " << fixed << setprecision(2) << sortedStudents[i].avg
                         << " | Grade: " << computeGrade(sortedStudents[i].avg) << "\n";
                }
                break;
            }
            case 5:
            {
                cout << "Exiting...\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
