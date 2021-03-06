// 8.feladat
	#include "std_lib_facilities.h"
	


	
	struct Person
	{
	public:
		Person() {}
		Person(string s, int n) { init(s, n); }
	
		void init(string s, int n)
		{
			checkName(s);
			checkAge(n);
	
			m_name = s;
			m_age = n;
		}
	
		string getName() const { return m_name; }
		int getAge() const { return m_age; }
	
	private:
		void checkAge(int n);
		void checkName(string s);
	
		string m_name;
		int m_age;
	};
	
	void Person::checkAge(int n)
	{
	
		unsigned int difference = 150 - n;
		if (difference > 150)
			error("Age needs to be in range 0 - 150");
	}
	
	void Person::checkName(string s)
	{
		size_t result = s.find_first_of(";:[]*&^%$#@!");
		if (result == string::npos)
			return;
	
		error("Names cannot contain the following: ;:\"\'[]*&^%$#@!");
	}
	
	ostream& operator<<(ostream& o, const Person& p) 
	{ 
		o << p.getName() << ": " << p.getAge() << endl; 
		return o; 
	}
	
	istream& operator>>(istream& i, Person& p)
	{
		string s;
		int a;
		cout << "Name: "; getline(i, s); 
		cout << "Age: "; i >> a; 
	
		p.init(s, a);
	
		return i;
	}
	



	
	int main()
	{
		
		Person p1{ "Goofy", 63 };
		cout << p1 << endl;
	
		Person p2;
		cin >> p2;
		cout << p2 << endl;
	
		_getch();
		return 0;
	}
	