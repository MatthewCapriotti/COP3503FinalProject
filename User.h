#ifndef User
#define User

#include <string>

class Actor
{
    protected:
        std::string const userID;
        std::string password;
        bool isSignedIn;

    public:
        virtual bool userNameTaken(std::string possibleID);
        virtual const std::string getUserID(std::string referenceOfAuthentication) = 0;
        virtual const std::string getPassword() = 0;
        virtual void setPassword(std::string newPassword) = 0;
        virtual bool isAuthenticated(std::string userID, std::string password) = 0;
};

class member: public Actor
{
    private:
        std::string const name;
        int const age;
        char const gender;
        std::string email;
        std::string phoneNum;
        std::string city;
        std::string state;
        std::string zipcode;

    public:
        member(std::string userID, std::string password, std::string name, 
                int age, char gender, std::string email, 
                std::string city, std::string state, std::string zipcode):name(name),age(age),gender(gender)

        //interface abstract methods
        bool userNameTaken(std::string possibleID);
        bool isAuthenticated(std::string userID, std::string password);
        const std::string getUserID(std::string email);
        const std::string getPassword(std::string email);
        void setPassword(std::string newPassword);

        //independent functions for a member of Gainz Ville
        const std::string getName(std::string userID);
        const int getAge(std::string userID);
        const char getGender(std::string userID);
        std::string getEmail(std::string userID);
        std::string getPhoneNum(std::string userID);
        std::string getCity(std::string userID);
        std::string getState(std::string userID);
        std::string getZipCode(std::string userID);
        void changeEmail(bool isAuthenticated(std::string userID, std::string password));
        void changePhoneNum(bool isAuthenticated(std::string userID, std::string password));
        void changeCity(bool isAuthenticated(std::string userID, std::string password));
        void changeState(bool isAuthenticated(std::string userID, std::string password));
        void changeZipCode(bool isAuthenticated(std::string userID, std::string password));
};

class admin: public Actor
{
    private:
        std::string adminCode;
    public:
        admin(std::string userID, std::string password, std::string adminCode);
        bool userNameTaken(std::string possibleID);
        bool isAuthenticated(std::string userID, std::string password);
        const std::string getUserID(std::string adminCode);
        const std::string getPassword(std::string adminCode);
};


#endif 