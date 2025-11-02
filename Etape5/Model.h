#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <cstring>

using namespace std;

namespace carconfig
{
	enum Engine{Petrol, Diesel, Electric, Hybrid};

	class Model
	{
		private:
			string Name;
			int Power;
			float basePrice;
			Engine engine;

		public:
			Model();
			Model(const string&, const int, const Engine, const float);
			Model(const Model &source);

			void setName(const string&);
			void setPower(const int);
			void setbasePrice(const float);
			void setEngine(const Engine);

			float getbasePrice() const;
			string getName() const;
			int getPower() const;
			Engine getEngine() const;

			friend istream& operator>>(istream& is, Model& m);
        	friend ostream& operator<<(ostream& os, const Model& m);

			void display() const;
	};
	

}
#endif