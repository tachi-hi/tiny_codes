#include<iostream>
#include"tropical.hpp"

using namespace std;

int main(int argc, char **argv){
	Tropical a(10.), b(20.), c(13.), d("0"), e(15.), f(0.), g(-30.);
	cerr << "a = " << a.show_value() << endl;
	cerr << "b = " << b.show_value() << endl;
	cerr << "c = " << c.show_value() << endl;
	cerr << "d = " << d.show_value() << endl;
	cerr << "e = " << e.show_value() << endl;
	cerr << "f = " << f.show_value() << endl;
	cerr << "g = " << g.show_value() << endl << endl;
	cerr << "a (+) b = " << (a + b).show_value() << endl;
	cerr << "a (+) c = " << (a + c).show_value() << endl;
	cerr << "a (+) d = " << (a + d).show_value() << endl;
	cerr << "a (+) e = " << (a + e).show_value() << endl;
	cerr << "a (+) f = " << (a + f).show_value() << endl;
	cerr << "a (+) g = " << (a + g).show_value() << endl << endl;
	cerr << "a (*) b = " << (a * b).show_value() << endl;
	cerr << "a (*) c = " << (a * c).show_value() << endl;
	cerr << "a (*) d = " << (a * d).show_value() << endl;
	cerr << "a (*) e = " << (a * e).show_value() << endl;
	cerr << "a (*) f = " << (a * f).show_value() << endl;
	cerr << "a (*) g = " << (a * g).show_value() << endl << endl;;
	g *= d;
}

