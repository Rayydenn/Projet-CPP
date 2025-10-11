#ifndef OPTION_H
#define OPTION_H
#include <cstring>
#include <iostream>

using namespace std;

namespace carconfig
{
	class Option
	{
		private:
			string Code;
			string Label;
			float Prix;

		public:
			Option();
			Option(const string&, const string&, const float);
			Option(const Option &source);

			string getCode();
			float getPrice();

			void display();

	};
}
#endif