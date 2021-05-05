#include "std_lib_facilities.h"

//g++ -std=c++11 d15_class_definition.cpp -o d15_cd -Wall

class Person{

public:

	Person(){};
	Person(string fn, string ln, int age);

	string get_fname() const {return firstName;}
	string get_lname() const {return lastName;}
	int get_age() const {return a;}


private:

	string firstName;
	string lastName;
	int a;
};

Person::Person(string fn, string ln, int age) : firstName{fn}, lastName{ln}, a{age}
{

	if (age > 150 || age < 0) error("Invalid age. ");


	for (char c : fn) {
		if (!isalpha(c)) error("Invalid firstNameame. ");

	}

	for (char c : ln) {
		if (!isalpha(c)) error("Invalid lastNameame. ");
	}

}


ostream& operator<<(ostream& os, const Person& p)
{
	os << "First Name: "<< p.get_fname() << "\n Last Name: " << p.get_lname() << "\n Age: " << p.get_age() << endl;

    return os;
}

istream& operator>>(istream& is, Person& p){

	string fn;
	string ln;
	int a;

	is >> fn;
	is >> ln;
	is >> a; 


	p = Person(fn, ln, a);

	return is;
}



int main()
try{

	Person p;

	vector <Person> pv;

	cout << "Enter names and ages: \n";


	for (Person p; cin >> p; ){

		if (p.get_fname() == "x")
			break;
		pv.push_back(p);
	}

	for(Person p : pv){

		cout << p << endl;
	}

	

}
catch(exception&e){
	cerr<< "exception: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch(...){
	cerr << "error";
	keep_window_open();
	return 2;
}