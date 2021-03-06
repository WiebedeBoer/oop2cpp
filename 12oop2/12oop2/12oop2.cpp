// 12oop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Overloading the << operator

//Create overloaded operator<< functions in the critter_farm.cpp program so that
//cout << crit << endl;
//will display a critter’s name and
//cout << myFarm << endl;
//will display the names of all critters in a farm.
//Don’t forget to declare the respective functions a friend of Critter and Farm so they can access the private members.
//p209

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class critter
class Critter {
public:
	Critter(const string &name = "");

	string GetName() const;

	friend ostream &operator<<(ostream &os, const Critter &aCritter);

private:
	string m_Name;
};

Critter::Critter(const string &name) :
	m_Name(name) {}

inline string Critter::GetName() const {
	return m_Name;
}

/*
Critter::Critter(const string& name) :
	m_Name(name)
{}

//peeking
void Peek(const Critter& aCritter)
{
	cout << aCritter.m_Name << endl;
}
*/

/*
//overloading operator
ostream& operator<<(ostream& os, const Critter& aCritter)
{
	os << "Critter Object - ";
	os << "m_Name: " << aCritter.m_Name;
	return os;
}
*/

//inline string Critter::GetName() const
//{
//	return m_Name;
//}

//class farm
class Farm {
public:
	Farm(int spaces = 1);

	void Add(const Critter &aCritter);

	void RollCall() const;

	friend ostream &operator<<(ostream &os, const Farm &farm);
private:
	vector<Critter> m_Critters;
};

Farm::Farm(int spaces) {
	m_Critters.reserve(spaces);
}

void Farm::Add(const Critter &aCritter) {
	m_Critters.push_back(aCritter);
}

void Farm::RollCall() const {
	for (vector<Critter>::const_iterator iter = m_Critters.begin();
		iter != m_Critters.end();
		++iter) {
		cout << iter->GetName() << " here.\n";
	}
}

/*
ostream &operator<<(ostream &os, const Farm &farm) {
	for (vector<Critter>::const_iterator iter = farm.m_Critters.begin();
		iter != farm.m_Critters.end();
		++iter) {
		os << iter->GetName() << endl;
	}

	return os;
}
*/

/*
void Farm::RollCall() const
{
	for (vector<Critter>::const_iterator iter = m_Critters.begin();
		iter != m_Critters.end();
		++iter)
	{
		//cout << iter->GetName() << " here.\n";
		//cout << Peek() << " here.\n";
		//cout << iter->Peek() << " here.\n";
	}
}
*/

/*
void Farm::RollCall(void)
{
	for (vector<Critter>::const_iterator iter = m_Critters.begin(); iter != m_Critters.end(); iter++)
	{
		cout << "Calling " << iter->getName() << "\n";
	}
}
*/

//rollcall
//void RollCall(const Farm& aFarm)
//{
	//for (vector<Critter>::const_iterator iter = aFarm.begin();
	//	iter != m_Critters.end();
	//	++iter)
	//{
		//cout << iter->GetName() << " here.\n";
	//	cout << Peek() << " here.\n";
		//cout << iter->Peek() << " here.\n";
	//}
//}

/*
//overloading operator
ostream& operator<<(ostream& os, const Farm& aFarm)
{
	os << "Farm Object - ";
	//os << "m_Critters: " << aFarm.m_Critters;
	return os;
}
*/

/*
void Peek(const Critter& aCritter);
ostream& operator<<(ostream& os, const Critter& aCritter);
void RollCall(const Farm& aFarm);
ostream& operator<<(ostream& os, const Farm& aFarm);
*/

//main
int main()
{
	Critter crit("Poochie");
	//cout << "My critter's name is " << crit.GetName() << endl;

	//cout << "Calling Peek() to access crit's private data member, m_Name: \n";
	//Peek(crit);

	cout << "Sending crit object to cout with the << operator: \n";
	cout << crit << endl;

	cout << "\nCreating critter farm.\n";
	Farm myFarm(3);

	cout << "\nAdding three critters to the farm.\n";
	myFarm.Add(Critter("Moe"));
	myFarm.Add(Critter("Larry"));
	myFarm.Add(Critter("Curly"));

	//cout << "\nCalling Roll...\n";
	//RollCall(myFarm);
	//myFarm.RollCall();
	//cout << myFarm << endl;
	cout << "\nCalling Roll...\n" << myFarm;

	return 0;
}

ostream &operator<<(ostream &os, const Critter &aCritter) {
	os << aCritter.m_Name;
	return os;
}

ostream &operator<<(ostream &os, const Farm &farm) {
	for (vector<Critter>::const_iterator iter = farm.m_Critters.begin();
		iter != farm.m_Critters.end();
		++iter) {
		os << iter->GetName() << endl;
	}

	return os;
}


/*
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class critter
class Critter
{
public:
	//Critter(const string& name = "");
	//string GetName() const;
	//friend void Peek(const Critter& aCritter); //peeking
	//friend ostream& operator<<(ostream& os, const Critter& aCritter);
	Critter(const string& name = "", int age = 0);
	~Critter(); //destructor prototype
	Critter(const Critter& c); //copy constructor prototype
	Critter& operator=(const Critter& c);
	op
		void Greet() const;

private:
	string m_Name;
	string m_pName;
};


//Critter::Critter(const string& name) :
//	m_Name(name)
//{}

//constructor
Critter::Critter(const string& name)
{
	cout << "constructor called\n";
	//string* m_pName = new string(name);
	m_pName = new string(name);
}


//destructor
Critter::~Critter()
{
	cout << "destructor called\n";
	delete m_pName;
}

//copy constructor
Critter::Critter(const Critter& c)
{
	cout << "copy constructor called\n";
	m_pName = new string(*(c.m_pName));
}


//overloading critter
Critter& Critter::operator= (const Critter& c) 
//Critter& operator=(const Critter& c)
{
	cout << "overloaded";
	if (this != &c) {
		delete m_pName;
		m_pName = new string(*(c.m_pName));
	}
	return *this;
}

//inline string Critter::GetName() const
//{
//	return m_Name;
//}


void Critter::Greet() const
{
	cout << "I’m " << *m_pName << ".\n";
	cout << "&m_pName: " << cout << &m_pName << endl;
}

//class farm
class Farm
{
public:
	Farm(int spaces = 1);
	void Add(const Critter& aCritter);
	void RollCall() const;

private:
	vector<Critter> m_Critters;
};

Farm::Farm(int spaces)
{
	m_Critters.reserve(spaces);
}

void Farm::Add(const Critter& aCritter)
{
	m_Critters.push_back(aCritter);
}

void Farm::RollCall() const
{
	for (vector<Critter>::const_iterator iter = m_Critters.begin();
		iter != m_Critters.end();
		++iter)
	{
		cout << iter->GetName() << " here.\n";
	}
}

//peeking
void Peek(const Critter& aCritter) 
{
	cout << aCritter.m_Name << endl;
}

//overloading operator
ostream& operator<<(ostream& os, const Critter& aCritter)
{
	os << "Critter Object - ";
	os << "m_Name: " << aCritter.m_Name;
	return os;
}

int main()
{
	Critter crit("Poochie");
	//cout << "My critter's name is " << crit.GetName() << endl;

	cout << "Calling Peek() to access crit's private data member, m_Name: \n";
	Peek(crit);

	cout << "\nCreating critter farm.\n";
	Farm myFarm(3);

	cout << "\nAdding three critters to the farm.\n";
	myFarm.Add(Critter("Moe"));
	myFarm.Add(Critter("Larry"));
	myFarm.Add(Critter("Curly"));

	cout << "\nCalling Roll...\n";
	myFarm.RollCall();

	return 0;
}
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
