#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <conio.h>

struct users
{
    std::string username;
    std::string password;
    bool isfull = 0;
};

int main()
{
    std::vector<int> id[1];

    int userquantity = 1;

    bool press = 0;

    std::string usernamelogin, passwordlogin;

    users user[100];

    bool usernamehasset = 0;

    while (press == 0)
    {
        system("cls");
        std::cout << "Press 1 to Log in | Press 2 to Sign in\n";

        if ((GetKeyState('1') & 0x8000))
        {
            Sleep(100);
            system("cls");
            std::cout << "|Introduce your username|\n";
            std::cin >> usernamelogin;
            system("cls");
            std::cout << "|Introduce your password|\n";
            std::cin >> passwordlogin;
            system("cls");
            for (int i = 1; i < 100; i++)
            {
                if (usernamelogin.compare(user[i].username) == 0)
                {
                    if (passwordlogin.compare(user[i].password) == 0)
                    {
                        std::cout << "You have souccessfully logged in";
                        Sleep(1000);
                        system("cls");
                        i = 100;
                    }
                    else
                    {
                        std::cout << "The username/password is incorrect";
                        Sleep(1000);
                        i = 100;
                    }
                }
            }
        }
        if ((GetKeyState('2') & 0x8000))
        {
            for (int i = 1; i < 100; i++)
            {
                if (user[i].isfull == 0)
                {
                    system("cls");

                    if (usernamehasset == 0)
                    {
                        std::cout << "|Itroduce your username|\n";
                        std::cin >> user[i].username;
                        for (int j = 0; j < i; j++)
                        {
                            if (user[j].username.compare(user[i].username) == 0)
                            {
                                system("cls");
                                std::cout << "This username is already taken\n";
                                Sleep(1000);
                                j = 100;
                                i = 0;
                            }
                            else if (user[i].username.length() < 3)
                            {
                                system("cls");
                                std::cout << "The username is too short\n";
                                Sleep(1000);
                                j = 100;
                                i = 0;
                            }
                            else if (j == i - 1)
                            {
                                j = 100;
                                usernamehasset = 1;
                            }
                        }
                    }
                    if (usernamehasset == 1)
                    {
                        system("cls");
                        std::cout << "|Introduce your password|\n";
                        std::cin >> user[i].password;
                        for (int j = 0; j < i; j++)
                        {
                            if (user[i].password.length() < 3)
                            {
                                std::cout << "This password is too short\n";
                                j = 0;
                                i = 0;
                            }
                            else
                            {
                                std::cout << "|You have successfully signed in|\n Username: " << user[i].username << std::endl << "Password: " << user[i].password << std::endl;
                                user[i].isfull = 1;
                                j = 100;
                                i = 100;
                                usernamehasset = 0;
                                Sleep(3000);
                            }
                        }
                    }
                }
            }
        }
    }
}