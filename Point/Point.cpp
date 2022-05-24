////На базі класу Точка на площині створіть клас Точка3D  (точка в просторі). Реалізуйте методи введення, виведения.+ 
////Реалізуйте методи за допомогою даних класів клас Відрізок, що дозволяє працювати з точками розмірностей 2 та 3.
////введення та виведення, визначення довжини відрізка,
////Вказівка: вианачіть додатковий член "розмірність" в класах Точка, Точка3Д Додаткова задача визначення чи перетинаються два відрізки.
//https://ua.onlinemschool.com/math/library/analytic_geometry/lines_intersection можна реалізувати перевірку через рівнняня прямої в просторі 
#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

class Point {//клас Точка 2D
protected:
	double x1;
	double y1;
	int dimension;
public:
	Point() {
		this->x1 = 0;
		this->y1 = 0;
		this->dimension = 2;
	}	
	void input() {//метод введення координат 
		cout << "Введіть координати точки на площиі x1, y1:" << endl;
		cin >> x1 >>  y1 ;
	}
	double getX() { return this->x1; }
	double getY() { return this->y1; }
	int getDimension() { return this->dimension; }
	

	void output() {//метод виведеня координат 
		cout << "Kоординати точки на площині x1, y1:" << endl;
		cout<< x1<<" "<< y1;
	}

	~Point() {}
};
class Point3D {//клас Точка 3D
protected:	
	double x1;
	double y1;
	double z1;
	int dimension;
public:	
	Point3D() {
		this->x1 = 0;
		this->y1 = 0;
		this->z1 = 0;
		this->dimension = 3;
	}
	void Input3D() {//метод введення координат 
	
		cout << "Введіть координати точки в просторі  x1, y1, z1:" << endl;
		cin >> x1 >> y1>> z1;
	}

	double getX() { return this->x1; }
	double getY() { return this->y1; }
	double getZ() { return this->z1; }
	int getDimension() { return this->dimension; }

    void Output3D() {//метод виведеня координат
		cout << "Kоординати точки в просторі  x1, y1, z1:" << endl;
		cout << x1 <<" " << y1<<" "<< z1;
	}
	~Point3D() {}
};
class Segment : public Point, public Point3D {
protected:
	double XY, XYZ;
public:
	Segment() 
	{
		this->XY = 0; this->XYZ = 0;	
	}
	double Segment_2D(Point &one, Point& two) {	// знаходимо довжину відрізка на площині
	XY = sqrt(pow((two.getX()- one.getX()), 2) + pow((two.getY() - one.getY()), 2));	
	return XY;
	}

	double Segment_3D(Point3D& on, Point3D& tw) {// знаходимо довжину відрізка в просторі
		XYZ = sqrt(pow((tw.getX() - on.getX()), 2) + pow((tw.getY() - on.getY()), 2) + pow((tw.getZ() - on.getZ()), 2));
		return XYZ;
	}
	bool cheakCrossing(Point& one, Point& two, Point3D& on, Point3D& tw) {//перевірка на перетин відрізків
		if (on.getZ() == 0 or tw.getZ() == 0) {
			if ((one.getX() == on.getX() and one.getY() == on.getY()) or (two.getX() == tw.getX() and two.getY() == tw.getY())) { return true; }//перевіряєм чи  точка в 3D лежить на 

			else if ((one.getX() == tw.getX() and one.getY() == tw.getY()) or (two.getX() == on.getX() and two.getY() == on.getY())) { return true; }//точці початку чи кінці відрізка  2D 
	//ще можна зробити перевірку чи відрізки лежать один на одному і ще можна зробити перевірку за допомогою рівняння прямої але потрібно реалізовувати калькулятор для систем рівннянь
		}
		else { return false; }
	}   


	~Segment() {}
};

int main()
{
	SetConsoleOutputCP(1251);
	Point a;//створення обєкту класу точка (створення першої точки)
	a.input();//метод введення координат 
	Point b;//створення обєкту класу точка (створення другої точки)
	b.input();//метод введення координат 

	Point3D c;//створення обєкту класу точка3D (створення першої точки)
	c.Input3D();//метод введення координат 

	Point3D d;//створення обєкту класу точка3D (створення другої точки)
	d.Input3D();//метод введення координат 

	Segment A;	//створення обєкту класу відрізок 
	cout << endl;
	a.output();//метод виведеня координат
	cout << endl;
	b.output();//метод виведеня координат
	cout << endl;
	c.Output3D();//метод виведеня координат
	cout << endl;
	d.Output3D();//метод виведеня координат
	cout << endl;

	cout << "\nДовжина відрізка в "<<a.getDimension()<<"D розмірності =" << A.Segment_2D(a, b) << endl << endl;
	cout << "Довжина відрізка в " << c.getDimension() << "D розмірності ="<< A.Segment_3D(c, d)<<endl << endl;
	if (A.cheakCrossing(a, b, c, d) == 1) 
	{
		cout << "Відрізки перетинаються" << endl;
	}
	else
	{
		cout << "Відрізки не перетинаються " << endl;
		cout << "Або перетинаються ,я не реалізував усі варіанти перетинання відрізків " << endl;
		cout << "Тому Вам потрібно самим це перевірити (^.^)  " << endl;
	
	}
	
}
