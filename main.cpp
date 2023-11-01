#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Player
{
private:
	int age_;
	string name_;
	string team_;

public:
	Player(int age, string name, string team): name_(name), team_(team) { 
        setAge(age);
	}
    void SwapTeam(string newTeam)
	{
		team_ = newTeam;
	}

    int getAge(){return age_;}

    void setAge(int age){
		if(age < 0){
			throw invalid_argument("age is invalid");
		}
        age_ = age;
    }

};

class Person{
private:
    string name;    
    string personalNumber;    
public:
    Person(string personalNumber)
        :Person(personalNumber,"")
    {
    }    
    Person(string personalNumber, string name){
        this->personalNumber = personalNumber;
        this->name = name;
    }    

    ~Person(){
        //delete dynamically  allocated things
    }

    Person(const Person &other)
        :Person(other.personalNumber,other.name)
    {
        cout << "Copy constructor called" << endl;
    }    
    
    Person& operator=(const Person &other)
    {
        this->personalNumber = other.personalNumber;
        this->name = other.name;
        cout << "Copy assigment called" << endl;
    }    


};

int main()
{
    Player player(51,"Peter Forsberg", "Modo");
    player.setAge(-12);
    cout << player.getAge() << endl;
    player.SwapTeam("Colorado Avalanche");




    Person p("12345");
    Person p2("123454","Stefan");

    


    Person p3 = p;
    Person p4(p);

    p4 = p3;

}