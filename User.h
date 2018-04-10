#ifndef User
#define User

#include <string>

class Actor
{
    protected:
        std::string username;
        std::string password;
        bool isSignedIn;

    public:
        virtual bool userNameTaken(std::string possibleID);
        virtual std::string getUsername(std::string referenceOfAuthentication) = 0;
        virtual std::string getPassword() = 0;
        virtual void setPassword(std::string newPassword) = 0;
        virtual bool isAuthenticated(std::string username, std::string password) = 0;
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
        member(std::string username, std::string password, std::string name, 
                int age, char gender, std::string email, 
                std::string city, std::string state, std::string zipcode);
        member();

        //interface abstract methods
        bool userNameTaken(std::string possibleID);
        bool isAuthenticated(std::string username, std::string password);
        std::string getUsername(std::string email);
        std::string getPassword(std::string email);
        void setPassword(std::string newPassword);

        //independent functions for a member of Gainz Ville
        std::string getName(std::string username);
        int getAge(std::string username);
        char getGender(std::string username);
        std::string getEmail(std::string username);
        std::string getPhoneNum(std::string username);
        std::string getCity(std::string username);
        std::string getState(std::string username);
        std::string getZipCode(std::string username);
        void setName(std::string username, std::string name);
        void setAge(std::string username, int age);
        void setGender(std::string username, char gender);
        void setUsername(std::string username, bool userNameTaken(std::string possibleID));
        void changeEmail(bool isAuthenticated(std::string username, std::string password));
        void changePhoneNum(bool isAuthenticated(std::string username, std::string password));
        void changeCity(bool isAuthenticated(std::string username, std::string password));
        void changeState(bool isAuthenticated(std::string username, std::string password));
        void changeZipCode(bool isAuthenticated(std::string username, std::string password));
};

class admin: public Actor
{
    private:
        std::string adminCode;
    public:
        admin(std::string username, std::string password, std::string adminCode);
        admin();
        bool userNameTaken(std::string possibleID);
        bool isAuthenticated(std::string username, std::string password);
        std::string getUsername(std::string adminCode);
        std::string getPassword(std::string adminCode);
};


#endif 