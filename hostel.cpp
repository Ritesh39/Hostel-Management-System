#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class hostel
{
private:
    int sIndex;
    string RegNo;
    string sName;
    string sYear;
    string sBranch;
    string sRoom;

    string roomNo;
    int roomCapacity;
    int availableCapacity;

public:
    void home();
    void administrator();
    void addRoom();
    void ModifyRoom();
    void removeRoom();
    void removeStudent();
    void listRooms();
    void listStudents();
    void student();
    void allocateRoom();
};

void hostel ::home()
{
start:
    int choice;
    string email;
    string password;

    cout << "\n\t\t\t\t_____________________________\n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t  Welcome to Sahyadri Hostel   \n";
    cout << "\t\t\t\t_____________________________\n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t|  1) Administrator          |\n";
    cout << "\t\t\t\t|                            |\n";
    cout << "\t\t\t\t|  2) Student                |\n";
    cout << "\t\t\t\t|                            |\n";
    cout << "\t\t\t\t|  3) Exit                   |\n";
    cout << "\t\t\t\t|                            |\n";
    cout << "\n\t\t\t Please select: ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        cout << "\t\t\t Please Login \n ";
        cout << "\n\t\t\t Enter Email: ";
        cin >> email;
        cout << "\n\t\t\t Enter password: ";
        cin >> password;

        if (email == "ritesh@gmail.com" && password == "Ritesh@123")
        {
            administrator();
        }
        else
        {
            cout << "\t\t\t Invalid email or password\n";
        }
        break;
    case 2:
        student();

    case 3:
        exit(0);

    default:
        cout << "Please select from the given options \n";
    }
    goto start;
}

void hostel ::administrator()
{

    int choice;
    cout << "\n\n\n\t\t\t Administrator menu\n";
    cout << "\n\t\t\t|_____ 1) Add the Room_________|";
    cout << "\n\t\t\t|                              |";
    cout << "\n\t\t\t|_____ 2) Modify the Room _____|";
    cout << "\n\t\t\t|                              |";
    cout << "\n\t\t\t|_____ 3) Delete the Room _____|";
    cout << "\n\t\t\t|                              |";
    cout << "\n\t\t\t|_____ 4) Delete the Student___|";
    cout << "\n\t\t\t|                              |";
    cout << "\n\t\t\t|_____ 5) List All Rooms ______|";
    cout << "\n\t\t\t|                              |";
    cout << "\n\t\t\t|_____ 6) List All Students ___|";
    cout << "\n\t\t\t|                              |";
    cout << "\n\t\t\t|_____ 7) Back to Main menu ___|\n";

    cout << "\nplease enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        addRoom();
        break;
    case 2:
        ModifyRoom();
    case 3:
        removeRoom();
        break;
    case 4:
        removeStudent();
        break;
    case 5:
        listRooms();
        break;
    case 6:
        listStudents();
        break;
    case 7:
        home();
        break;
    default:
        cout << "Invalid choice\n";
    }
    administrator();
}

void hostel ::student()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t Student menu\n";
    cout << "\n\t\t\t|___ 1) Allocate the Room____|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|___ 2) Go back _____________|";
    cout << "\n\t\t\t|                            |\n";
    cout << "\n\t\t\t Enter your choice :";
    cin >> choice;

    switch (choice)
    {
    case 1:
        allocateRoom();
        break;
    case 2:
        home();
        break;
    default:
        cout << "invalid choice ";
    }
    goto m;
}

void hostel ::addRoom()
{
start:
    fstream data;
    int token = 0;
    // int i;
    string n;
    int c;
    int ac;

    listRooms();

    cout << "\n\n\t\t\t Add new Room ";
    cout << "\n\n\t Number of the Room: ";
    cin >> roomNo;
    cout << "\n\n\t Capacity of the Room: ";
    cin >> roomCapacity;
    availableCapacity = roomCapacity;

    data.open("roomdb.txt", ios::in);
    if (!data)
    {
        data.open("roomdb.txt", ios::app | ios::out);
        data << roomNo << "  " << roomCapacity << "  " << availableCapacity << "\n";
        data.close();
    }
    else
    {
        data >> n >> c >> ac;

        while (!data.eof())
        {
            if (n == roomNo)
            {
                token++;
            }
            data >> n >> c >> ac;
        }
        data.close();

        if (token == 1)
        {
            cout << "Room already exist...!\n";
            goto end;
        }
        else
        {
            data.open("roomdb.txt", ios::app | ios::out);
            data << roomNo << "  " << roomCapacity << "  " << availableCapacity << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t Room Record inserted !\n";
end:
    char response;
    cout << "want to add another Room(y/n): ";
    cin >> response;
    if (response == 'y' || response == 'Y')
    {
        goto start;
    }

    administrator();
}

void hostel ::ModifyRoom()
{
start:
    fstream data, data1;
    string rkey;
    int token = 0;
    string n;
    int c;
    int ac;

    listRooms();

    cout << "\n\t\t\t Modify the room record";
    cout << "\n\t\t\t Room No :";
    cin >> rkey;

    data.open("roomdb.txt", ios::in);
    if (!data)
    {
        cout << "\n\n file doesn't exist !";
        goto end;
    }
    else
    {
        data1.open("roomdb1.txt", ios::app | ios::out);
        data >> roomNo >> roomCapacity >> availableCapacity;
        while (!data.eof())
        {
            if (rkey == roomNo)
            {
                cout << "\n\t\t New Room No :";
                cin >> n;
                cout << "\n\t\t New Room Capacity :";
                cin >> c;
                cout << "\n\t\t New Available Capacity :";
                cin >> ac;
                data1 << " " << n << " " << c << " " << ac << "\n";
                cout << "\n\n\t\t Room Record edited\n";
                token++;
            }
            else
            {
                data1 << roomNo << "  " << roomCapacity << "  " << availableCapacity << "\n";
            }
            data >> roomNo >> roomCapacity >> availableCapacity;
        }

        data.close();
        data1.close();

        // rename roomdb1.txt to roomdb.txt
        remove("roomdb.txt");
        rename("roomdb1.txt", "roomdb.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found sorry !\n";
        }
    }
end:
    char response;
    cout << "want to Modify another Room(y/n): ";
    cin >> response;
    if (response == 'y' || response == 'Y')
    {
        goto start;
    }

    administrator();
}

void hostel ::removeRoom()
{
start:
    fstream data, data1;
    string rkey;
    int token = 0;

    listRooms();

    cout << "\n\n\t Delete Room";
    cout << "\n\n\t Room No :";
    cin >> rkey;

    data.open("roomdb.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist\n";
    }
    else
    {
        data1.open("roomdb1.txt", ios::app | ios::out);
        data >> roomNo >> roomCapacity >> availableCapacity;
        while (!data.eof())
        {
            if (roomNo == rkey)
            {
                if (availableCapacity < roomCapacity)
                {
                    cout << "Students are Allocated to this Room\n";
                    cout << "So, Room can not be deleted...!\n";
                    data.close();
                    data1.close();
                    remove("roomdb1.txt");

                    goto end;
                }
                else
                {
                    cout << "\n\n\t Room deleted successfully\n";
                    token++;
                }
            }
            else
            {
                data1 << roomNo << "  " << roomCapacity << "  " << availableCapacity << "\n";
            }
            data >> roomNo >> roomCapacity >> availableCapacity;
        }
        data.close();
        data1.close();
        remove("roomdb.txt");
        rename("roomdb1.txt", "roomdb.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    end:
        char response;
        cout << "Want to Delete another Room(y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y')
        {
            goto start;
        }
        else
        {
            administrator();
        }
    }
}

void hostel ::removeStudent()
{
start:
    fstream sdata, sdata1, rdata, rdata1;
    string skey;
    int token = 0;

    listStudents();

    cout << "\n\n\t Delete Student Record";
    cout << "\n\n\t Student Reg No :";
    cin >> skey;
    sdata.open("studentdb.txt", ios::in);
    if (!sdata)
    {
        cout << "File doesn't exist\n";
    }
    else
    {
        sdata1.open("studentdb1.txt", ios::app | ios::out);
        sdata >> RegNo >> sName >> sYear >> sBranch >> sRoom;
        while (!sdata.eof())
        {
            if (RegNo == skey)
            {
                cout << "\n\n\t Student Record deleted successfully\n";

                rdata.open("roomdb.txt", ios::in);

                rdata1.open("roomdb1.txt", ios::app | ios::out);
                rdata >> roomNo >> roomCapacity >> availableCapacity;
                while (!rdata.eof())
                {
                    if (roomNo == sRoom)
                    {
                        cout << "\n\n\t RoomNo " << roomNo << " Record Updated successfully\n";
                        rdata1 << roomNo << "  " << roomCapacity << "  " << availableCapacity + 1 << "\n";
                        token++;
                    }
                    else
                    {
                        rdata1 << roomNo << "  " << roomCapacity << "  " << availableCapacity << "\n";
                    }
                    rdata >> roomNo >> roomCapacity >> availableCapacity;
                }
                rdata.close();
                rdata1.close();
                remove("roomdb.txt");
                rename("roomdb1.txt", "roomdb.txt");

                if (token == 0)
                {
                    cout << "\n\n Room Record not found\n";
                }

                token++;
            }
            else
            {
                sdata1 << RegNo << "  " << sName << "  " << sYear << "  " << sBranch << "  " << sRoom << "\n";
            }
            sdata >> RegNo >> sName >> sYear >> sBranch >> sRoom;
        }
        sdata.close();
        sdata1.close();

        remove("studentdb.txt");
        rename("studentdb1.txt", "studentdb.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found\n"
                 << endl
                 << endl;
        }
    end:
        char response;
        cout << "\n\n Do you want to remove another student (y/n) : ";
        cin >> response;
        if (response == 'y' || response == 'Y')
        {
            goto start;
        }
        administrator();
    }
}

void hostel ::allocateRoom()
{
start:
    fstream rdata, sdata, rdata1;
    int stoken = 0, rtoken = 0;
    string Rn;
    string ns;
    string temp;
    string y;
    string b;
    string r;

    rdata.open("roomdb.txt", ios::in);
    if (!rdata)
    {
        cout << "No Roooms Available...!\n"
             << endl;
        return student();
    }

    cout << "\n\n   Available Rooms are";
    cout << endl;

    listRooms();

    cout << "\n\t\t Allocate Room\n";
    cout << "\n\t Enter RoomNo: ";
    cin >> r;

    rdata1.open("roomdb1.txt", ios::app | ios::out);
    rdata >> roomNo >> roomCapacity >> availableCapacity;
    while (!rdata.eof())
    {
        if (r == roomNo && availableCapacity > 0)
        {
            cout << "\n\n\t\t\t Add new Student";
            cout << "\n\n\t Reg No: ";
            cin >> Rn;
            cout << "\n\n\t Name (First name and Last name only): ";
            cin >> temp;
            ns += temp;
            cin >> temp;
            ns += "_" + temp;
            cout << "\n\n\t Year: ";
            cin >> y;
            cout << "\n\n\t Branch: ";
            cin >> b;

            sdata.open("studentdb.txt", ios::in);
            if (!sdata)
            {
                sdata.open("studentdb.txt", ios::app | ios::out);
                sdata << Rn << "  " << ns << "  " << y << "  " << b << "  " << r << "\n";
                sdata.close();
            }
            else
            {
                sdata >> RegNo >> sName >> sYear >> sBranch >> sRoom;

                while (!sdata.eof())
                {
                    if (Rn == RegNo)
                    {
                        stoken++;
                    }
                    sdata >> RegNo >> sName >> sYear >> sBranch >> sRoom;
                }
                sdata.close();

                if (stoken == 1)
                {
                    cout << "Student Already Present in Hostel List...!\n"
                         << endl;
                    goto end;
                }
                else
                {
                    sdata.open("studentdb.txt", ios::app | ios::out);
                    sdata << Rn << "  " << ns << "  " << y << "  " << b << "  " << r << "\n";
                    sdata.close();
                }
            }
            cout << "\n\n\t\t Student Record inserted !\n";

            rdata1 << roomNo << "  " << roomCapacity << "  " << availableCapacity - 1 << "\n";
            cout << "\n\n\t\t Room Record edited\n";
            rtoken++;
        }
        else
        {
            rdata1 << roomNo << "  " << roomCapacity << "  " << availableCapacity << "\n";
        }
        rdata >> roomNo >> roomCapacity >> availableCapacity;
    }

    rdata.close();
    rdata1.close();

    // rename roomdb1.txt to roomdb.txt
    remove("roomdb.txt");
    rename("roomdb1.txt", "roomdb.txt");

    if (rtoken == 0)
    {
        cout << "\n\n This Room is Not Available...!\n";
    }
end:
    char response;
    cout << "\n\n Do you want to Allocate another student (y/n) : ";
    cin >> response;
    if (response == 'y' || response == 'Y')
    {
        goto start;
    }
}

void hostel ::listRooms()
{
    fstream data;
    data.open("roomdb.txt", ios::in);
    cout << "\n____________________________________________\n";
    cout << " Room No"
         << "\t"
         << "Capacity"
         << "\t"
         << "Available";
    cout << "\n____________________________________________\n";
    data >> roomNo >> roomCapacity >> availableCapacity;
    while (!data.eof())
    {
        cout << " " << roomNo << "\t\t" << roomCapacity << "\t\t" << availableCapacity << "\n";
        data >> roomNo >> roomCapacity >> availableCapacity;
    }
    data.close();
}

void hostel ::listStudents()
{
    fstream data;
    data.open("studentdb.txt", ios::in);
    cout << "\n\n_______________________________________________________________________________\n";
    cout << "Reg No    "
         << "\t\t"
         << "Name"
         << "\t\t"
         << "Year"
         << "\t\t"
         << "Branch"
         << "\t\t"
         << "Room No";
    cout << "\n_______________________________________________________________________________\n";
    data >> RegNo >> sName >> sYear >> sBranch >> sRoom;
    while (!data.eof())
    {
        cout << RegNo << "\t\t" << sName << "\t" << sYear << "\t\t" << sBranch << "\t\t" << sRoom << "\n";
        data >> RegNo >> sName >> sYear >> sBranch >> sRoom;
    }
    data.close();
}

int main()
{

    hostel h;
    h.home();

    return 0;
}