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
			Option(const string, const string, const float);
			Option(const Option &source);
			~Option();

			void setCode(const string n);
			void setLabel(const string l);
			void setPrice(const float p);

			string getCode() const;
			string getLabel() const;
			float getPrice() const;

			void display() const;

	};
}
#endif