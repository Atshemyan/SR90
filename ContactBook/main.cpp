#include "ContactBook.hpp"

int main(int argc, char const *argv[])
{
    ContactBook CB;
    CB.AddContact("Name", "Surname", "+37498287550", "simplenamestudent@gmail.com");
    
    CB.ViewAllContacts();
    return 0;
}
