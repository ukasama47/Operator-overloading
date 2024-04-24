
#include <iostream>
#include <math.h>
using namespace std;

class Complex {
  double a, b;
  public:
  Complex() { //要素
		a = 0, b = 0; 
	}
  Complex(double _a, double _b) { //初期化
		a = _a, b = _b; 
	}
  void output_value(){
	  if (a != 0 && b != 0) {
		  if (b > 0) {
	      cout << a << "+" << b << "i";
	    } else {
		    cout << a << b << "i";
		  }
	  } else if (a == 0 && b == 0) {
	    cout << 0;		
	  }	else if (a == 0 && b != 0) {
		  cout << b << "i";
	  }	else if (a != 0 && b == 0) {
		  cout << a;
    }		
	}
  Complex operator+ (Complex &object2);
  Complex operator- (Complex &object2);
  Complex operator* (Complex &object2);
  Complex operator/ (Complex &object2);
  bool operator == (Complex &object2) {
	  return a == object2.a && b == object2.b;
  }
};

Complex Complex::operator+ (Complex &object2) {
  Complex add;
  add.a = a + object2.a;
	add.b = b + object2.b;
	return add;
}
Complex Complex::operator- (Complex &object2) {
	Complex sub;
  sub.a = a - object2.a;
	sub.b = b - object2.b;
	return sub;
}
Complex Complex::operator* (Complex &object2) {
	Complex mult;
  mult.a = a * object2.a - b * object2.b;
	mult.b = a * object2.b + b * object2.a;
	return mult;
}
Complex Complex::operator/ (Complex &object2) {
	Complex div;
	div.a = (a * object2.a + object2.b * b)/(pow(object2.a, 2) + pow(object2.b, 2));
	div.b = (b * object2.a - a * object2.b)/(pow(object2.a, 2) + pow(object2.b, 2));
	return div;
}

int main() {
	Complex obj3;
	double re, im;
	cout << "object1の実部 object1の虚部 object2の実部 object2の虚部 の順に数字を入力して改行してください" << endl;
	cin >> re >> im;
	Complex obj1(re,im);
	//cout << "object2：実部→スペース→虚部の順に入力して改行してください" << endl;
	cin >> re >> im;
	Complex obj2(re,im);	
	
	obj3 = obj1 + obj2;
  obj1.output_value();
	cout << " + (";
  obj2.output_value();
	cout << ") = ";	
	obj3.output_value();
	cout << endl;		
	
	obj3 = obj1 - obj2;
  obj1.output_value();
	cout << " - (";
  obj2.output_value();
	cout << ") = ";	
	obj3.output_value();
	cout << endl;		
	
	obj3 = obj1 * obj2;
  obj1.output_value();
	cout << " × (";
  obj2.output_value();
	cout << ") = ";	
	obj3.output_value();	
	cout << endl;		
	
	obj3 = obj1 / obj2;
  obj1.output_value();
	cout << " ÷ (";
  obj2.output_value();
	cout << ") = ";	
	obj3.output_value();	
	cout << endl;		

	if (obj1 == obj2) {
		cout << "obj1 = obj2" << endl;	
	} else {
		cout << "obj1 ≠ obj2" << endl;	
	}
}
