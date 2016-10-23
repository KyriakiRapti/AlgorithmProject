#include <iostream>
using namespace std; 

class date{
	public:
		void set(int, int, int);
		void get(int &, int &, int &); //anafores

	private:
		int day, month, year;

};

int main(void)
{
	date today;
	date *ptoday=&today;

	int d,m,y;

	today.set(3,18,2005);
	today.get(m,d,y);

	cout << "day" << d << ", month " << m << " , year" << y << endl;

	ptoday->get(m,d,y);
	cout << "day " << d << ", month " << m << " y year " << y << endl;

	return 0;

}

void date::set(int i, int j, int k)
{
	month= i;
	day = j;
	year = k;
}

void date::get(int& i, int& j, int& k)
{
	i=month;
	j=day;
	k=year;
}
