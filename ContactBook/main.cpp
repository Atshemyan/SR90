#include "ContactBook.hpp"

int main(int argc, char const *argv[])
{
    ContactBook CB;
    CB.AddContact("Gogs", "Arz", "+37498487050", "gohararzumanyanstudent@gmail.com");
    
    CB.ViewAllContacts();
    return 0;
}
