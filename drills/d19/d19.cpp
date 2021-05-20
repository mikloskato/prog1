#include "../GUI/std_lib_facilities.h"


template<typename T> 
struct S{

	S() {};
	S(T v) : val{v} {}

	T& get();
	const T& get() const;

	S<T>& operator=(const T& v)
	{
		val= v;
		return *this;
	}

private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T& S<T>::get() const
{
	return val;
}


template<typename T>
void read_val(T& v)
{
	cin >> v;
	if(!cin) error("Bad input!");
}


int main()
{

	S<int> i ={2021};
	S<string> s {"Valami"};
	S<char> c {'c'};
	S<double> d {31.76};
	S<vector<int>> v {vector<int>{1, 2, 3, 4, 5}};

	cout << "INT: "<< i.get() << endl;
	cout << "STRING: "<< s.get() << endl;
	cout << "CHAR: " << c.get() << endl;
	cout << "DOUBLE: " << d.get() << endl;
	cout << "VECTOR: ";
	for(auto& a : v.get())
		cout << a << " ";
	cout << endl;

	int i_read;
	cout << "Please enter an INTEGER: ";
	read_val(i_read);
	i = i_read;
	
	string s_read;
	cout << "Please enter a STRING: ";
	read_val(s_read);
	s = s_read;
	
	char c_read;
	cout << "Please enter a CHARACTER: ";
	read_val(c_read);
	c = c_read;
	
	double d_read;
	cout << "Please enter a DOUBLE: ";
	read_val(d_read);
	d = d_read;
	cout << '\n';
	
	cout << "INT: "<< i.get() << endl;
	cout << "STRING: "<< s.get() << endl;
	cout << "CHAR: "<< c.get() << endl;
	cout << "DOUBLE: "<< d.get() << endl;

	return 0;
}
