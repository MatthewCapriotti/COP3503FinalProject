#ifndef User
#define User

#include <string>

class Actor
{
    protected:
        std::string userID;
        std::string password;
        bool isSignedIn;

    public:
        virtual bool userNameTaken(std::string possibleID);
        virtual std::string getUserID(std::string referenceOfAuthentication) = 0;
        virtual std::string getPassword() = 0;
        virtual void setPassword(std::string newPassword) = 0;
        virtual bool isAuthenticated(std::string userID, std::string password) = 0;
};

class member: public Actor
{
    private:
        std::string name;
        int age;
        char gender;
        std::string email;
        std::string phoneNum;
        std::string city;
        std::string state;
        std::string zipcode;

    public:
        member(std::string userID, std::string password, std::string name, 
                int age, char gender, std::string email, 
                std::string city, std::string state, std::string zipcode);
        member();

        //interface abstract methods
        bool userNameTaken(std::string possibleID);
        bool isAuthenticated(std::string userID, std::string password);
        std::string getUserID(std::string email);
        std::string getPassword(std::string email);
        void setPassword(std::string newPassword);

        //independent functions for a member of Gainz Ville
        std::string getName(std::string userID);
        int getAge(std::string userID);
        char getGender(std::string userID);
        std::string getEmail(std::string userID);
        std::string getPhoneNum(std::string userID);
        std::string getCity(std::string userID);
        std::string getState(std::string userID);
        std::string getZipCode(std::string userID);
        void setName(std::string userID);
        void setAge(std::string userID);
        void setGender(std::string userID);
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
        admin();
        bool userNameTaken(std::string possibleID);
        bool isAuthenticated(std::string userID, std::string password);
        std::string getUserID(std::string adminCode);
        std::string getPassword(std::string adminCode);
};


#endif 