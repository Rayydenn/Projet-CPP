#include <iostream>

using namespace std;

namespace carconfig
{
	class Option
	{
	private:
		char Code[5];
		char *Label;
		float Price;

	public:
		Option();
		Option(const char*, const char*, float);
		Option(const Option &source);
		~Option();

		void setCode(const char*);
		void setLabel(const char*);
		void setPrice(float);


		void display();
	};
}

