class Phone
{
    private:
        std::string m_phonenumber = "NONE";

    public:
        bool CheckValid(std::string phonenumber) 
        {
            if (phonenumber.size() < 12)
            {
                return false;
            }

            std::string trueforphone = "+374";
            for (int i = 0; i < trueforphone.size() - 1; ++i)
            {
                if (phonenumber[i] != trueforphone[i])
                {
                    return 0;
                }
                
            }
            return 1;
        }

        void SetPhone(std::string phonenumber)
        {
            
            while (!CheckValid(phonenumber))
            {
                std::cout << "InCurrect phone number, try again! \n";
                std::cin >> phonenumber;
            }

            m_phonenumber = phonenumber;   
        }

        std::string GetPhone() const
        {
            return m_phonenumber;
        }
    
};

