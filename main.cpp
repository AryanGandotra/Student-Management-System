#include <iostream>
#include <unistd.h>
#include <iomanip>
using namespace std;

class Node
{
public:
    int rollNumber;
    string name;
    float phy_marks;
    float chem_marks;
    float maths_marks;
    float percentage;
    Node *next;
};

class LinkedList
{
public:
    Node *head = NULL;
    void insert()
    {
        int r;
        string n;
        float m1, m2, m3;
        cout << "Enter roll number: ";
        cin >> r;
        cout << "Enter name: ";
        cin >> n;
        cout << "Enter marks in Physics: ";
        cin >> m1;
        cout << "Enter marks in Chemistry: ";
        cin >> m2;
        cout << "Enter marks in Maths: ";
        cin >> m3;
        Node *new_node = new Node;
        new_node->rollNumber = r;
        new_node->name = n;
        new_node->phy_marks = m1;
        new_node->chem_marks = m2;
        new_node->maths_marks = m3;
        new_node->percentage = ((m1 + m2 + m3) * 100 / 300);
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node *p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = new_node;
        }

        cout << "\nNew Student added successfully" << endl;
    }

    void search()
    {
        if (head == NULL)
        {
            cout << "\nNo record exists" << endl;
        }
        else
        {
            int r, found = 0;
            cout << "\nEnter roll number to search: ";
            cin >> r;
            Node *p = head;
            while (p)
            {
                if (p->rollNumber == r)
                {
                    cout << "\nRoll Number: " << p->rollNumber << endl;
                    cout << "\nName: " << p->name << endl;
                    cout << "\nMarks in physics: " << p->phy_marks << endl;
                    cout << "\nMarks in chemistry: " << p->chem_marks << endl;
                    cout << "\nMarks in maths: " << p->maths_marks << endl;
                    cout << "\nPercentage: " << p->percentage << endl;
                    found = 1;
                }
                p = p->next;
            }
            if (found == 0)
            {
                cout << "\nRoll number " << r << " not found in records" << endl;
            }
        }
    }

    void count()
    {
        if (head == NULL)
        {
            cout << "\nNo records found" << endl;
        }
        else
        {
            Node *p = head;
            int count = 0;
            while (p)
            {
                count++;
                p = p->next;
            }

            cout << "\nTotal Number of students in record: " << count << endl;
        }
    }

    void update()
    {
        if (head == NULL)
        {
            cout << "\nNo record exists" << endl;
        }
        else
        {
            int r, found = 0;
            cout << "\nEnter roll number to update: ";
            cin >> r;
            Node *p = head;
            while (p)
            {
                if (p->rollNumber == r)
                {
                    cout << "Enter new roll number: ";
                    cin >> p->rollNumber;
                    cout << "Enter new name: ";
                    cin >> p->name;
                    cout << "Enter new marks in Physics: ";
                    cin >> p->phy_marks;
                    cout << "Enter new marks in Chemistry: ";
                    cin >> p->chem_marks;
                    cout << "Enter new marks in Maths: ";
                    cin >> p->maths_marks;
                    p->percentage = (p->phy_marks + p->chem_marks + p->maths_marks) / 3;
                    cout << "\nRecord updated successfully" << endl;
                    found = 1;
                }
                p = p->next;
            }
            if (found == 0)
            {
                cout << "\nRoll number " << r << " not found in records" << endl;
            }
        }
    }

    void deletion()
    {
        if (head == NULL)
        {
            cout << "\nNo record exists" << endl;
        }
        else
        {
            int r, found = 0;
            cout << "\nEnter roll number to delete: ";
            cin >> r;
            if (r = head->rollNumber)
            {
                Node *p = head;
                head = head->next;
                delete p;
                found++;
                cout << "\nRecord deleted successfully" << endl;
            }
            else
            {
                Node *p = head;
                Node *temp = NULL;
                while (p != NULL)
                {
                    if (r = p->rollNumber)
                    {
                        temp->next = p->next;
                        p->next = NULL;
                        delete p;
                        found++;
                        cout << "\nRecord deleted successfully" << endl;
                        break;
                    }
                    temp = p;
                    p = p->next;
                }
            }
            if (found == 0)
            {
                cout << "\nRoll number " << r << " not found in records" << endl;
            }
        }
    }

    void show()
    {
        if (head == NULL)
        {
            cout << "\nNo record exists" << endl;
        }
        else
        {
            cout.setf(ios::left);
            cout << setw(15) << "Roll Number";
            cout << setw(15) << "Name";
            cout << setw(20) << "Marks in physics";
            cout << setw(20) << "Marks in chemistry";
            cout << setw(20) << "Marks in maths";
            cout << setw(20) << "Percentage";
            cout << endl;
            Node *p = head;
            while (p)
            {
                if (p)
                {
                    cout.setf(ios::left);
                    cout << setw(15) << p->rollNumber;
                    cout << setw(15) << p->name;
                    cout << setw(20) << p->phy_marks;
                    cout << setw(20) << p->chem_marks ;
                    cout << setw(20) << p->maths_marks;
                    cout << setw(20) << p->percentage;
                    cout << endl;
                }
                p = p->next;
            }
        }
    }
};

int main()
{
    LinkedList l1;
    int choice;

jump:
    system("clear");

    cout << "\n1.Insert Record of new Student" << endl;
    cout << "\n2.Search Record of existing Student" << endl;
    cout << "\n3.Count total number of students" << endl;
    cout << "\n4.Update record of existing student" << endl;
    cout << "\n5.Delete record of existing student" << endl;
    cout << "\n6.Show records of all students" << endl;
    cout << "\n7.Exit" << endl;
    cout << "\nEnter your choice: ";

    cin >> choice;
    switch (choice)
    {
    case 1:
        system("clear");
        l1.insert();
        break;
    case 2:
        system("clear");
        l1.search();
        break;
    case 3:
        system("clear");
        l1.count();
        break;
    case 4:
        system("clear");
        l1.update();
        break;
    case 5:
        system("clear");
        l1.deletion();
        break;
    case 6:
        system("clear");
        l1.show();
        break;
    case 7:
        exit(0);
        break;
    default:
        cout << "Invalid choice! Please try again ..." << endl;
    }
    fflush(stdin);
    getchar();
    goto jump;
    return 0;
}