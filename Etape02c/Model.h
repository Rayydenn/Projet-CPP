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

			float getbasePrice();

			void display();
	};
	

}
#endif