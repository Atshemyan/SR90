#include "ContactBook.hpp"


int main(int argc, char const *argv[])
{
    int command = 0;

    while (command != 6)
    {
        ContactBook CB;
        std::cout << "1) See all contacts \n";
        std::cout << "2) Add Contact \n";
        std::cout << "3) Find contact by name \n";
        std::cout << "4) Update contact by id \n";
        std::cout << "5) Remove contact by id \n";
        std::cout << "6) Quit \n";
        std::cout << "Command: ";
        std::cin >> command;
        std::cout << "\n";
        while(command < 0 || command > 6)
        {
            std::cout << "Incurrect command, try again! \n";
            std::cout << "Command: ";
            std::cin >> command;
        }

        switch (command)
        {
        case 1:
            CB.ViewAllContacts();
            break;
        case 2:
        {
            std::string name, surname, phone, mail;
            std::cout << "Write name: ";
            std::cin >> name;
            std::cout << "\n";

            std::cout << "Write surname: ";
            std::cin >> surname;
            std::cout << "\n";

            std::cout << "Write number: ";
            std::cin >> phone;
            std::cout << "\n";

            std::cout << "Write mail: ";
            std::cin >> mail;
            std::cout << "\n";

            CB.AddContact(name, surname, phone, mail);
            break;
        }

        case 3:
        {
            std::string name;
            std::cout << "Write name: ";
            std::cin >> name;
            std::cout << "\n";
            CB.FindContact(name);
            break;
        }

        case 4:
        {
            int id;
            std::cout << "Write Id: ";
            std::cin >> id;
            while(id <= 0 || id > CB.GetSize())
            {
                std::cout << "Incurrect id, try again! \n";
                std::cout << "id: ";
                std::cin >> id;
            }

            std::cout << "\n";

            std::string name, surname, phone, mail;
            std::cout << "Write name: ";
            std::cin >> name;
            std::cout << "\n";

            std::cout << "Write surname: ";
            std::cin >> surname;
            std::cout << "\n";

            std::cout << "Write number: ";
            std::cin >> phone;
            std::cout << "\n";

            std::cout << "Write mail: ";
            std::cin >> mail;
            std::cout << "\n";

            CB.UpdateContact(id, name, surname, phone, mail);
            break;
            
        }

        case 5:
        {
            int id;
            std::cout << "Write Id: ";
            std::cin >> id;
            while(id < 0 || id > CB.GetSize())
            {
                std::cout << "Incurrect id, try again! \n";
                std::cout << "id: ";
                std::cin >> id;
            }
            std::cout << "\n";

            CB.RemoveContact(id);
            break;
        }

        default:
            break;
        }
    }
    
}
