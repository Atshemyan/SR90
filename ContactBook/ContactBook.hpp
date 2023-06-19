#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Mail.hpp"
#include "Phone.hpp"

class ContactBook
{
    private:
        unsigned int id = 0;
        std::vector<std::tuple<int, std::string, std::string, Phone, Mail> > m_contats;
        std::fstream file;
        
    public:
        ContactBook()
        {
            
            if (!file.is_open())
            {
                file.open("data.txt");
            }
            
            std::string line;
            int counter = 0;
            std::string name;
            std::string surname;
            Mail mailinstance;
            Phone phoneinstance;

            while (std::getline(file, line))
            {
                std::string word;
                std::stringstream stream(line);

                while (stream >> word)
                { 
                    switch (counter)
                    {
                    case 0:
                        id = std::stoi(word);
                        break;

                    case 1:
                        name = word;
                        break;

                    case 2:
                        surname = word;
                        break;

                    case 3:
                        phoneinstance.SetPhone(word); 
                        break;
                    case 4:
                        mailinstance.SetMail(word); 
                        break;

                    default:
                        break;
                    }
                    
                    ++counter;
                    
                }
                counter = 0;
                m_contats.push_back(std::make_tuple(id, name, surname, phoneinstance, mailinstance));
            }

        }

        ~ContactBook()
        {  
            file.close();
            file.open("data.txt");
            for (int i = 0; i < m_contats.size(); i++)
            {
                file << std::get<0>(m_contats[i]) << " ";
                file << std::get<1>(m_contats[i]) << " ";
                file << std::get<2>(m_contats[i]) << " ";
                file << std::get<3>(m_contats[i]).GetPhone() << " ";
                file << std::get<4>(m_contats[i]).GetMail() << "\n";
            }
            
            file.close();
        }

        void AddContact(std::string name, std::string surname, std::string phonenumber, std::string mail)
        {
            Phone phoneinstance;
            phoneinstance.SetPhone(phonenumber);
            Mail mailinstance;
            mailinstance.SetMail(mail);
            m_contats.push_back(std::make_tuple(++id, name, surname, phoneinstance, mailinstance));
        }

        void RemoveContact(int id)
        {
            while (id <= 0 || id > m_contats.size())
            {
                std::cout << "Incorrect ID, try again! \n";
                std::cin >> id;
            }

            m_contats.erase(m_contats.begin() + (id - 1));
            
        }

        void UpdateContact(int id, std::string name, std::string surname, std::string phonenumber, std::string mail)
        {   
            Phone phoneinstance;
            phoneinstance.SetPhone(phonenumber);
            Mail mailinstance;
            mailinstance.SetMail(mail);
            m_contats[id - 1] = std::make_tuple(id, name, surname, phoneinstance, mailinstance);
        }
    
        void FindContact(std::string name)
        {
            int countoffinded = 0;
            for (int i = 0; i < m_contats.size(); i++)
            {
                if (std::get<1>(m_contats[i]) == name)
                {
                    ++countoffinded;
                    std::cout << "Finded No" << countoffinded << "\n";
                    std::cout << std::get<0>(m_contats[i]);
                    std::cout << "\n";
                    std::cout << std::get<1>(m_contats[i]);
                    std::cout << "\n";
                    std::cout << std::get<2>(m_contats[i]);
                    std::cout << "\n";
                    std::cout << std::get<3>(m_contats[i]).GetPhone();
                    std::cout << "\n";
                    std::cout << std::get<4>(m_contats[i]).GetMail();
                    std::cout << "\n";
                    
                }
                
            }
            if (countoffinded == 0)
            {
                std::cout << "Not found :( \n";
            }
            
            return;
        }

        void ViewAllContacts()
        {
            for (int i = 0; i < m_contats.size(); i++)
            {
                std::cout << std::get<0>(m_contats[i]) << " ";
                std::cout << std::get<1>(m_contats[i]) << " ";
                std::cout << std::get<2>(m_contats[i]) << " ";
                std::cout << std::get<3>(m_contats[i]).GetPhone() << " ";
                std::cout << std::get<4>(m_contats[i]).GetMail() << " ";
                std::cout << std::endl; 
            }

        }
};
