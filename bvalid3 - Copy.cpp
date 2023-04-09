#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
using namespace std;

// Global variables
const int length = 5;
int allIndex, optionSelect, redwrit_count = 0, signup_count = 0, feedcount = 0;
string signInName;
string signInPassword;
string name[length];
string role[length];
string password[length];
string data[length];
float accountMoney[length];
string feeds[length];
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// Functions
void firstMenu();
void header();
void signUp();
bool checksignIn();
void updatePass();
void adminMenu();
void employee();
void userMenu();
void exit();
float subtract(float accountMoney, float withdraw);
void firstOption();
void mainSecondOption();
float balance();
void moneyTransfer();
void pasLenSignUp();
void Delete();
void empDelete();
void view();
float currency();
void feedback();
void showfeed();
void mainSecondAdmin();
void mainSecondEmployee();
void mainSecondUser();
void writeInFile();
string seperate(string line, int idx);
void toArray();
void readFromFile();
void deposit();

bool checkintstring(string num);
bool checkUpPass(string pass);

main()
{
    // main variables
    int counting;
    string options;
    int flag = 0;
    readFromFile();
    toArray();
    while (true)
    {
        system("cls");

        header();
        firstMenu();
        while (true)
        {
            SetConsoleTextAttribute(h, 6);
            cout << "Enter key: ";
            cin >> options;
            SetConsoleTextAttribute(h, 15);
            if (checkintstring(options))
            {
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid command." << endl;
                exit();
                SetConsoleTextAttribute(h, 15);
            }
        }
        counting = stoi(options);
        // all if calling commands

        while (true)
        {

            if (counting < 4 && counting >= 1)
            {
                if (counting == 1 && signup_count < length)
                {
                    signUp();
                    signup_count++;
                    writeInFile();
                    exit();
                    break;
                }
                else if (counting == 2)
                {
                    mainSecondOption();
                    exit();
                    break;
                }

                else if (counting == 3)
                {
                    flag++;
                    system("cls");
                    break;
                }
                else if (signup_count >= length)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "Sorry! You cannot sign Up because limit has been exceeded." << endl;
                    SetConsoleTextAttribute(h, 15);
                    exit();
                    break;
                }
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid command! " << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
                break;
            }
        }
        if (flag > 0)
        {
            break;
        }
    }
    writeInFile();
}

void header()
{
    SetConsoleTextAttribute(h, 10);
    cout << "               AAA                            QQQQQQQQQ           BBBBBBBBBBBBBBBBB                                      kkkkkkkk           " << endl;
    cout << "              A:::A                         QQ:::::::::QQ         B::::::::::::::::B                                     k::::::k           " << endl;
    cout << "             A:::::A                      QQ:::::::::::::QQ       B::::::BBBBBB:::::B                                    k::::::k           " << endl;
    cout << "            A:::::::A                    Q:::::::QQQ:::::::Q      BB:::::B     B:::::B                                   k::::::k           " << endl;
    cout << "           A:::::::::A                   Q::::::O   Q::::::Q        B::::B     B:::::B  aaaaaaaaaaaaa  nnnn  nnnnnnnn     k:::::k    kkkkkkk" << endl;
    cout << "          A:::::A:::::A                  Q:::::O     Q:::::Q        B::::B     B:::::B  a::::::::::::a n:::nn::::::::nn   k:::::k   k:::::k " << endl;
    cout << "         A:::::A A:::::A                 Q:::::O     Q:::::Q        B::::BBBBBB:::::B   aaaaaaaaa:::::an::::::::::::::nn  k:::::k  k:::::k  " << endl;
    cout << "        A:::::A   A:::::A                Q:::::O     Q:::::Q        B:::::::::::::BB             a::::ann:::::::::::::::n k:::::k k:::::k   " << endl;
    cout << "       A:::::A     A:::::A               Q:::::O     Q:::::Q        B::::BBBBBB:::::B     aaaaaaa:::::a  n:::::nnnn:::::n k::::::k:::::k    " << endl;
    cout << "      A:::::AAAAAAAAA:::::A              Q:::::O     Q:::::Q        B::::B     B:::::B  aa::::::::::::a  n::::n    n::::n k:::::::::::k     " << endl;
    cout << "     A:::::::::::::::::::::A             Q:::::O  QQQQ:::::Q        B::::B     B:::::B a::::aaaa::::::a  n::::n    n::::n k:::::::::::k     " << endl;
    cout << "    A:::::AAAAAAAAAAAAA:::::A            Q::::::O Q::::::::Q        B::::B     B:::::Ba::::a    a:::::a  n::::n    n::::n k::::::k:::::k    " << endl;
    cout << "   A:::::A             A:::::A           Q:::::::QQ::::::::Q      BB:::::BBBBBB::::::Ba::::a    a:::::a  n::::n    n::::nk::::::k k:::::k   " << endl;
    cout << "  A:::::A               A:::::A   ......  QQ::::::::::::::Q       B:::::::::::::::::B a:::::aaaa::::::a  n::::n    n::::nk::::::k  k:::::k  " << endl;
    cout << " A:::::A                 A:::::A  .::::.    QQ:::::::::::Q        B::::::::::::::::B   a::::::::::aa:::a n::::n    n::::nk::::::k   k:::::k " << endl;
    cout << "AAAAAAA                   AAAAAAA ......      QQQQQQQQ::::QQ      BBBBBBBBBBBBBBBBB     aaaaaaaaaa  aaaa nnnnnn    nnnnnnkkkkkkkk    kkkkkkk" << endl;
    cout << "                                                      Q:::::Q                                                                               " << endl;
    cout << "                                                       QQQQQQ                                                                               " << endl;
    SetConsoleTextAttribute(h, 15);
}

void firstMenu()
{
    SetConsoleTextAttribute(h, 10);
    cout << "     Main Menu" << endl;
    cout << "*******************************" << endl;
    cout << "1. Do you want to sign up?" << endl;
    cout << "2. Do you want to sign in?" << endl;
    cout << "3. Do you want to exit?" << endl;
    SetConsoleTextAttribute(h, 15);
}

void adminMenu()
{
    SetConsoleTextAttribute(h, 10);
    cout << "     Admin Menu" << endl;
    cout << "*******************************" << endl;
    cout << "1. Withdraw money?" << endl;
    cout << "2. Check balance?" << endl;
    cout << "3. Money transfer?" << endl;
    cout << "4. Add accounts?" << endl;
    cout << "5. Update password." << endl;
    cout << "6. Delete account." << endl;
    cout << "7. View accounts." << endl;
    cout << "8. View feedbacks." << endl;
    cout << "9. Exit" << endl;
    SetConsoleTextAttribute(h, 15);
}
void employee()
{
    SetConsoleTextAttribute(h, 10);
    cout << "     Employee Menu" << endl;
    cout << "*******************************" << endl;
    cout << "1. Withdraw money." << endl;
    cout << "2. Check balance." << endl;
    cout << "3. Money transfer." << endl;
    cout << "4. Add account." << endl;
    cout << "5. Update password." << endl;
    cout << "6. view accounts." << endl;
    cout << "7. Delete account." << endl;
    cout << "8. View feedbacks." << endl;
    cout << "9. Exit" << endl;
    SetConsoleTextAttribute(h, 15);
}

void userMenu()
{
    SetConsoleTextAttribute(h, 10);
    cout << "     User's Options" << endl;
    cout << "*******************************" << endl;
    cout << "1. Withdraw money." << endl;
    cout << "2. Check balance." << endl;
    cout << "3. Money transfer." << endl;
    cout << "4. Update password." << endl;
    cout << "5. Deposit amount" << endl;
    cout << "6. Deposit amount in dollars" << endl;
    cout << "7. Enter feedback." << endl;
    cout << "8. Exit" << endl;
    SetConsoleTextAttribute(h, 15);
}

void pasLenSignUp()
{
    while (true)
    {
        if (password[signup_count].size() != 8)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Enter password of 8 characters." << endl;
            cout << "Enter Password: ";
            cin >> password[signup_count];
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
}

void signUp()
{
    string options;
    float money;
    SetConsoleTextAttribute(h, 6);
    cout << "Enter name: ";
    cin.ignore();
    SetConsoleTextAttribute(h, 15);
    getline(cin, name[signup_count]);
    while (true)
    {
        SetConsoleTextAttribute(h, 6);
        cout << "Enter password: ";
        cin >> password[signup_count];
        SetConsoleTextAttribute(h, 15);
        pasLenSignUp();
        if (checkUpPass(password[signup_count]))
        {
            SetConsoleTextAttribute(h, 4);
            cout << "You cannot take this password. As it has been already taken." << endl;
            SetConsoleTextAttribute(h, 15);
            exit();
        }
        else
        {
            break;
        }
    }
    SetConsoleTextAttribute(h, 10);
    cout << "Enter role 'admin', 'employee', 'user': ";
    cin >> role[signup_count];
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (role[signup_count] != "admin" && role[signup_count] != "user" && role[signup_count] != "employee")
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Enter valid role: ";
            cin >> role[signup_count];
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        SetConsoleTextAttribute(h, 6);
        cout << "Enter amount in account: ";
        cin >> options;
        SetConsoleTextAttribute(h, 15);
        if (checkintstring(options))
        {
            break;
        }
        else
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Invalid amount." << endl;
            SetConsoleTextAttribute(h, 15);
            exit();
        }
    }
    money = stoi(options);
    accountMoney[signup_count] = money;
    SetConsoleTextAttribute(h, 10);
    cout << "You have successfuly created an account." << endl;
    SetConsoleTextAttribute(h, 15);
}

bool checksignIn()
{
    bool result = false;
    for (int i = 0; i < length; i++)
    {
        if (name[i] == signInName && password[i] == signInPassword)
        {
            allIndex = i;
            result = true;
            break;
        }
    }
    return result;
}

void exit()
{
    SetConsoleTextAttribute(h, 6);
    cout << "Press any key to exit.." << endl;
    SetConsoleTextAttribute(h, 15);
    getch();
}

void firstOption()
{
    float withdraw;
    string options;
    while (true)
    {
        while (true)
        {
            SetConsoleTextAttribute(h, 6);
            cout << "Enter amount: ";
            cin >> options;
            SetConsoleTextAttribute(h, 15);
            if (checkintstring(options))
            {
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
        }
        withdraw = stof(options);
        if (accountMoney[allIndex] >= withdraw)
        {
            if (withdraw <= 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Enter positive integer greater than zero." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
                continue;
            }
            subtract(accountMoney[allIndex], withdraw);
            SetConsoleTextAttribute(h, 10);
            cout << "Operation has been successfuly completed." << endl;
            cout << "Amount left in your account is: " << subtract(accountMoney[allIndex], withdraw) << endl;
            SetConsoleTextAttribute(h, 15);
            accountMoney[allIndex] = accountMoney[allIndex] - withdraw;
            exit();
            break;
        }
        else
        {
            SetConsoleTextAttribute(h, 4);
            cout << "You don't have enough money!" << endl;
            SetConsoleTextAttribute(h, 15);
        }
    }
}
void mainSecondAdmin()
{
    while (true)
    {
        system("cls");
        header();
        adminMenu();
        string options;
        while (true)
        {
            SetConsoleTextAttribute(h, 6);
            cout << "Enter key: ";
            cin >> options;
            SetConsoleTextAttribute(h, 15);
            if (checkintstring(options))
            {
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
        }
        optionSelect = stoi(options);
        if (optionSelect == 1)
        {
            firstOption();
            writeInFile();
        }
        else if (optionSelect == 2)
        {
            SetConsoleTextAttribute(h, 10);
            cout << "Amount in your account is: " << balance() << endl;
            SetConsoleTextAttribute(h, 15);
            exit();
        }
        else if (optionSelect == 3)
        {
            moneyTransfer();
            writeInFile();
        }
        else if (optionSelect == 4)
        {
            if (signup_count < length)
            {
                signUp();
                signup_count++;
                writeInFile();
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "You cannot add account as limit has been exceeded." << endl;
                SetConsoleTextAttribute(h, 15);
            }
            exit();
        }
        else if (optionSelect == 5)
        {
            updatePass();
            writeInFile();
            exit();
        }
        else if (optionSelect == 6)
        {
            Delete();
            writeInFile();
            SetConsoleTextAttribute(h, 10);
            cout << "Account Deleted successfuly";
            SetConsoleTextAttribute(h, 15);
            exit();
        }
        else if (optionSelect == 7)
        {
            view();
            exit();
        }
        else if (optionSelect == 8)
        {
            showfeed();
            exit();
        }
        else if (optionSelect == 9)
        {
            break;
        }
    }
}

void mainSecondEmployee()
{
    while (true)
    {
        string options;
        system("cls");
        header();
        employee();
        while (true)
        {
            SetConsoleTextAttribute(h, 6);
            cout << "Enter key: ";
            cin >> options;
            SetConsoleTextAttribute(h, 15);
            if (checkintstring(options))
            {
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
        }
        optionSelect = stoi(options);
        if (optionSelect == 1)
        {
            firstOption();
            writeInFile();
        }
        else if (optionSelect == 2)
        {
            SetConsoleTextAttribute(h, 10);
            cout << "Amount in your account is: " << balance() << endl;
            SetConsoleTextAttribute(h, 15);
            exit();
        }
        else if (optionSelect == 3)
        {
            moneyTransfer();
            writeInFile();
        }
        else if (optionSelect == 4)
        {
            if (signup_count < length)
            {
                signUp();
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "You cannot add account as limit has been exceeded." << endl;
                SetConsoleTextAttribute(h, 15);
            }
            writeInFile();
            exit();
        }
        else if (optionSelect == 5)
        {
            updatePass();
            writeInFile();
            exit();
        }
        else if (optionSelect == 6)
        {
            view();
            exit();
        }
        else if (optionSelect == 7)
        {
            empDelete();
            writeInFile();
        }
        else if (optionSelect == 8)
        {
            showfeed();
        }
        else if (optionSelect == 9)
        {
            break;
        }
    }
}

void mainSecondUser()
{
    while (true)
    {
        string options;
        system("cls");
        header();
        userMenu();
        while (true)
        {
            SetConsoleTextAttribute(h, 6);
            cout << "Enter key: ";
            cin >> options;
            SetConsoleTextAttribute(h, 15);
            if (checkintstring(options))
            {
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
        }
        optionSelect = stoi(options);
        if (optionSelect == 1)
        {
            firstOption();
            writeInFile();
        }
        else if (optionSelect == 2)
        {
            SetConsoleTextAttribute(h, 10);
            cout << "Amount in your account is: " << balance() << endl;
            SetConsoleTextAttribute(h, 15);
            exit();
        }
        else if (optionSelect == 3)
        {
            moneyTransfer();
            writeInFile();
        }
        else if (optionSelect == 4)
        {
            updatePass();
            writeInFile();
            exit();
        }
        else if (optionSelect == 5)
        {
            deposit();
            writeInFile();
            exit();
        }
        else if (optionSelect == 6)
        {
            SetConsoleTextAttribute(h, 10);
            cout << "Now amount in your account is: " << currency() << endl;
            SetConsoleTextAttribute(h, 15);
            exit();
        }
        else if (optionSelect == 7)
        {
            feedback();
        }
        else if (optionSelect == 8)
        {
            break;
        }
        else if (optionSelect > 8 || optionSelect < 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Invalid command.";
            SetConsoleTextAttribute(h, 15);
            exit();
        }
    }
}
void mainSecondOption()
{
    SetConsoleTextAttribute(h, 6);
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, signInName);
    cout << "Enter your password: ";
    cin >> signInPassword;
    SetConsoleTextAttribute(h, 15);
    if (checksignIn())
    {
        if (role[allIndex] == "admin")
        {
            mainSecondAdmin();
        }
        else if (role[allIndex] == "employee")
        {
            mainSecondEmployee();
        }
        else
        {
            mainSecondUser();
        }
    }
    else
    {
        SetConsoleTextAttribute(h, 4);
        cout << "Invalid information" << endl;
        SetConsoleTextAttribute(h, 15);
    }
}

float balance()
{
    if (checksignIn())
    {
        return accountMoney[allIndex];
    }
}

void updatePass()
{
    if (checksignIn())
    {
        SetConsoleTextAttribute(h, 6);
        cout << "Enter new password: ";
        cin >> password[allIndex];
        SetConsoleTextAttribute(h, 15);
    }
    while (true)
    {
        if (password[allIndex].size() != 8)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Enter password of 8 characters." << endl;
            cout << "Enter new password: ";
            cin >> password[allIndex];
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
}

void moneyTransfer()
{
    firstOption();
}

float subtract(float accountMoney, float withdraw)
{
    float left = accountMoney - withdraw;
    return left;
}
void deposit()
{
    int money;
    SetConsoleTextAttribute(h, 4);
    cout << "How much money do you want to deposit: ";
    cin >> money;
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (money < 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Enter positive integer." << endl;
            SetConsoleTextAttribute(h, 6);
            cout << "How much money do you want to deposit: ";
            SetConsoleTextAttribute(h, 15);
            cin >> money;
        }
        else
        {
            break;
        }
    }
    accountMoney[allIndex] = accountMoney[allIndex] + money;
    SetConsoleTextAttribute(h, 10);
    cout << "You have been depsited " << money << " rupees." << endl;
    SetConsoleTextAttribute(h, 15);
}
void Delete()
{
    int idx;
    string Name, Password;
    SetConsoleTextAttribute(h, 6);
    cout << "Enter name: ";
    cin >> Name;
    cout << "Enter password: ";
    cin >> Password;
    SetConsoleTextAttribute(h, 15);
    for (int i = 0; i < signup_count; i++)
    {
        if (name[i] == Name && password[i] == Password)
        {
            idx = i;
            break;
        }
    }
    name[idx] = false;
    password[idx] = false;
    role[idx] = false;
    accountMoney[idx] = false;
    signup_count--;
    // redwrit_count--;
}
void empDelete()
{
    string Name, Password;
    SetConsoleTextAttribute(h, 6);
    cout << "Enter name: ";
    cin >> Name;
    cout << "Enter password: ";
    cin >> Password;
    SetConsoleTextAttribute(h, 15);
    for (int i = 0; i < signup_count; i++)
    {
        if (name[i] == Name && password[i] == Password)
        {
            if (role[i] == "admin")
            {
                SetConsoleTextAttribute(h, 4);
                cout << "You cannot delete this account as it is account of admin." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
                continue;
            }
            name[i] = false;
            password[i] = false;
            role[i] = false;
            accountMoney[i] = false;
            SetConsoleTextAttribute(h, 10);
            cout << "Operation successful." << endl;
            SetConsoleTextAttribute(h, 15);
            signup_count--;
            exit();
            break;
        }
    }
}

void view()
{
    SetConsoleTextAttribute(h, 10);
    cout << "Name \t Password \t Role \t Accout Money" << endl;
    SetConsoleTextAttribute(h, 6);
    for (int i = 0; i < signup_count; i++)
    {
        cout << name[i] << " \t " << password[i] << " \t " << role[i] << " \t " << accountMoney[i] << endl;
    }
    SetConsoleTextAttribute(h, 15);
}

float currency()
{
    float money;
    if (checksignIn())
    {
        string options;
        while (true)
        {
            SetConsoleTextAttribute(h, 6);
            cout << "Enter amount in dollars to add in account: ";
            cin >> options;
            SetConsoleTextAttribute(h, 15);
            if (checkintstring(options))
            {
                break;
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
        }
        money = stof(options);
        accountMoney[allIndex] = accountMoney[allIndex] + (money * 285);
        writeInFile();
        return accountMoney[allIndex];
    }
}

void feedback()
{
    string feed;
    SetConsoleTextAttribute(h, 6);
    cout << "Enter feedback in a single line: " << endl;
    cin.ignore();
    SetConsoleTextAttribute(h, 15);
    getline(cin, feed);
    feeds[feedcount] = feed;
    feedcount++;
}

void showfeed()
{
    for (int i = 0; i < feedcount; i++)
    {
        cout << feeds[i] << endl;
    }
}

bool checkintstring(string num)
{
    bool result = true;
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] > 57 || num[i] < 48)
        {
            result = false;
        }
    }
    return result;
}
bool checkUpPass(string pass)
{
    bool result = false;
    for (int i = 0; i < signup_count; i++)
    {
        if (pass == password[i])
        {
            result = true;
        }
    }
    return result;
}

// from here to write and read functions starts
void writeInFile()
{
    fstream write;
    write.open("data.csv", ios::out);
    for (int i = 0; i < signup_count; i++)
    {
        write << name[i] << "," << password[i] << "," << role[i] << "," << accountMoney[i] << endl;
    }
    write.close();
}

string seperate(string line, int idx)
{
    int comma = 1;
    string result = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            comma++;
        }
        else if (comma == idx)
        {
            result = result + line[i];
        }
    }
    return result;
}
void toArray()
{
    string line, money;
    for (int i = 0; i < length; i++)
    {
        line = data[i];
        name[i] = seperate(line, 1);
        password[i] = seperate(line, 2);
        role[i] = seperate(line, 3);
        money = (seperate(line, 4));
        accountMoney[i] = atoi(money.c_str());
        if (accountMoney[i] != 0)
        {
            signup_count++;
        }
    }
}
void readFromFile()
{
    fstream read;
    read.open("data.csv", ios::in);
    int i = 0;
    while (!(read.eof()))
    {
        getline(read, data[i]);
        cout << data[i] << endl;
        i++;
    }
    read.close();
}