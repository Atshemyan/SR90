class Mail
{
    private:
        std::string m_email = "NONE";

    public:
        bool CheckValid(std::string mail) 
        {
            if (mail.size() < 5)
            {
                return false;
            }
            std::string trueformail = "@mail.ru";
            std::string trueforgmail = "@gmail.com";
            unsigned int index1 = mail.size();
            unsigned int index2 = trueforgmail.size();
            for (int i = trueformail.size(); i >= 0; --i)
            {
                if (mail[index1] != trueforgmail[index2] && mail[index1] != trueformail[i])
                {
                    return 0;
                }
                --index1;
                --index2;
                
            }
            return 1;
        }
        
        void SetMail(std::string mail)
        {
           
            while (!CheckValid(mail))
            {
                std::cout << "InCurrect mail, try again! \n";
                std::cin >> mail;
            }

            m_email = mail;
                
        }
        
        std::string GetMail() const
        {
            return m_email;
        }
};

