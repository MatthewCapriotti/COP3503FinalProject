#ifndef User
#define User

#include <string>

class Actor
{
    protected:
        std::string username;
        std::string password;
        //bool isSignedIn;

    public:
        virtual std::string getUsername() = 0;
        virtual std::string getPassword() = 0;
        virtual void setPassword(std::string newPassword) = 0;
        virtual bool isAuthenticated(std::string usernameAttempt, std::string passwordAttempt) = 0;
        //virtual bool userNameTaken(std::string possibleID) = 0;
        //virtual bool emailIsValid(std::string email) = 0;
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
        
        //bool isAuthenticated(std::string username, std::string password);
        std::string getUsername();
        std::string getPassword();
        std::string getName();
        int getAge();
        char getGender();
        std::string getEmail();
        std::string getPhoneNum();
        std::string getCity();
        std::string getState();
        std::string getZipCode();
        bool isAuthenticated(std::string usernameAttempt, std::string passwordAttempt);
        void setPassword(std::string newPassword);
        void setName(std::string name);
        void setAge(int age);
        void setGender(char gender);
        void setUsername(std::string username);
        void setEmail(std::string newEmail);
        void setPhoneNum(std::string newPhoneNum);
        void setCity(std::string newCity);
        void setState(std::string newState);
        void setZipCode(std::string newZipCode);
};

class admin: public Actor
{
    private:
        std::string name;
        std::string email;
        std::string phoneNum;
    public:
        admin(std::string username, std::string password, std::string name, std::string email, std::string phoneNum);
        admin();
        //bool userNameTaken(std::string possibleID);
        //bool isAuthenticated(std::string username, std::string password);
        std::string getUsername();
        std::string getPassword();
        bool isAuthenticated(std::string usernameAttempt, std::string passwordAttempt);
        void setPassword(std::string newPassword);
        //void removeUser(std::string memberUsername);
};


#endif 