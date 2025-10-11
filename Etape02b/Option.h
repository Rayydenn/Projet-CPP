#include <iostream>

using namespace std;

namespace carconfig
{
	class Option
	{
	private:
		string Code;
		string Label;
		float Price;

	public:
		Option();
		Option(const string&, const string&, float);
		Option(const Option &source);

		void setCode(const string&);
		void setLabel(const string&);
		void setPrice(float);


		void display();
	};
}

