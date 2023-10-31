#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

class EMP_CLASS
{
    typedef struct EMPLOYEE
    {
        char name[10];
        int emp_id;
        int salary;
    } Rec;

    typedef struct INDEX
    {
        int emp_id;
        int position;
    } Ind_Rec;

    Rec Records;
    Ind_Rec Ind_Records;

public:
    EMP_CLASS();
    void Create();
    void Delete();
};

EMP_CLASS::EMP_CLASS() // constructor
{
    strcpy(Records.name, "");
}

void EMP_CLASS::Create()
{
    int i, j;
    char ch = 'y';
    fstream seqfile;
    fstream indexfile;
    i = 0;
    indexfile.open("IND.DAT", ios::out);
    seqfile.open("EMP.DAT", ios::out);
    do
    {
        cout << "\n Enter Name: ";
        cin >> Records.name;
        cout << "\n Enter Emp_ID: ";
        cin >> Records.emp_id;
        cout << "\n Enter Salary: ";
        cin >> Records.salary;
        seqfile.write((char *)&Records, sizeof(Records));
        Ind_Records.emp_id = Records.emp_id;
        Ind_Records.position = i;
        indexfile.write((char *)&Ind_Records, sizeof(Ind_Records));
        i++;
        cout << "\nDo you want to add more records?";
        cin >> ch;
    } while (ch == 'y');
    seqfile.close();
    indexfile.close();
}

void EMP_CLASS::Delete()
{
    int id, pos;
    cout << "\n For deletion,";
    cout << "\n Enter the Emp_ID for for searching ";
    cin >> id;
    fstream seqfile;
    fstream indexfile;
    seqfile.open("EMP.DAT", ios::in | ios::out | ios::binary);
    indexfile.open("IND.DAT", ios::in | ios::out | ios::binary);
    seqfile.seekg(0, ios::beg);
    indexfile.seekg(0, ios::beg);
    pos = -1;
    // reading index file for getting the index
    while (indexfile.read((char *)&Ind_Records, sizeof(Ind_Records)))
    {
        if (id == Ind_Records.emp_id) // desired record is found
        {
            pos = Ind_Records.position;
            Ind_Records.emp_id = -1;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "\n The record is not present in the file";
        return;
    }
    // calculating the position of record in seq. file using the pos of ind. file
    int offset = pos * sizeof(Rec);
    seqfile.seekp(offset); // seeking the desired record for deletion
    strcpy(Records.name, "");
    Records.emp_id = -1;                                       // logical deletion
    Records.salary = -1;                                       // logical deletion
    seqfile.write((char *)&Records, sizeof(Records)) << flush; // writing deleted status
                                                               // From index file also the desired record gets deleted as follows

    offset = pos * sizeof(Ind_Rec); // getting position in index file
    indexfile.seekp(offset);        // seeking that record
    Ind_Records.emp_id = -1;        // logical deletion of emp_id
    Ind_Records.position = pos;     // position remain unchanged
    indexfile.write((char *)&Ind_Records, sizeof(Ind_Records)) << flush;
    seqfile.seekg(0);
    indexfile.close();
    seqfile.close();
    cout << "\n The record is Deleted!!!";
}
int main()
{
    EMP_CLASS List;
    char ans;
    int choice;
    do
    {
        cout << "\n             Main Menu             " << endl;
        cout << "\n 1.Create";
        cout << "\n 2.Delete";
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            List.Create();
            break;
        case 2:
            List.Delete();
            break;
        }
        cout << "\n\t Do you want to go back to Main Menu?";
        cin >> ans;
    } while (ans == 'y');
}
