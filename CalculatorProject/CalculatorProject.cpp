#include <iostream>
#include<cmath>
#include<conio.h>
#include <algorithm>
#include <sstream>
using namespace std;
const int N = 100;

class factorial
{
public:
	int n;
	// рекурсивный метод подсчета факториала 
	double fact(int N)
	{
		if (N < 0) // если пользователь ввел отрицательное число
		{
			cout << "Вы ввели отрицательное число" << endl;
			return 0; // возвращаем ноль
		}
		else if (N == 0) // если пользователь ввел ноль,
		{
			return 1; // возвращаем факториал от нуля, который равен 1
		}
		else // во всех остальных случаях
		{
			return N * fact(N - 1); // выполняем рекурсивный вызовы функции
		}
	}
}obj;
class Vector {
public:
	double x, y, z;
	Vector vproiz(Vector obj) {
		Vector tmp;
		tmp.x = y * obj.z - obj.y * z;
		tmp.y = z * obj.x - obj.z * x;
		tmp.z = x * obj.y - obj.x * y;
		return tmp;
	}
	Vector sproiz(Vector obj) {
		Vector tmp;
		tmp.x = x * obj.x;
		tmp.y = y * obj.y;
		tmp.z = z * obj.z;
		return tmp;
	}
	void show() {
		cout << "(" << x << "," << y << "," << z << ")\n";
	}
};
class sinus
{
public:
	double x;
	double sin()
	{
		double q, s;
		int n;
		q = x;
		s = x;
		for (n = 1; n <= N; n++)
		{
			q *= (-1) * x * x / (2 * n) / (2 * n + 1);
			s += q;
		}
		return s;
	}
	double sin1()
	{
		double q, s;
		int n;
		q = x;
		s = x;
		for (n = 1; n <= N; n++)
		{
			cout << n << ":sin= " << s << endl;
			q *= (-1) * x * x / (2 * n) / (2 * n + 1);
			s += q;
		}
		return 0;
	}
};
struct complex {
	double a, b, r; // Структура, для группировки элементов a, b и r
};
class Complex {
	complex comp;
public:
	Complex(double x = 0, double y = 0, double z = 0) {
		comp.a = x;
		comp.b = y;
		comp.r = z;
	} // Метод для записи a, b и r
	Complex operator +(const Complex& c); // Оператор сложения
	Complex operator *(const Complex& c); // Оператор умножения
	Complex operator -(const Complex& c); // Оператор вычитания
	Complex operator /(const Complex& c); // Оператор деления
	const Complex& operator =(const Complex& c) {
		comp.a = c.comp.a; // Запись действительной части
		comp.b = c.comp.b; // Запись мнимой части
		comp.r = c.comp.r; // Запись коэффициента r для тригонометрической формы
		return *this;
	}
	Complex Read();
	Complex ReadTR();
	void Display();
};
Complex Complex::operator +(const Complex& c) {
	Complex d;
	d.comp.a = comp.r * comp.a + c.comp.a * c.comp.r;
	d.comp.b = comp.r * comp.b + c.comp.b * c.comp.r;
	return d;
} // Оператор сложения
Complex Complex::operator *(const Complex& c) {
	Complex t;
	t.comp.a = comp.r * comp.a * c.comp.a - c.comp.r * comp.b * c.comp.b;
	t.comp.b = comp.r * comp.a * c.comp.b + c.comp.r * comp.b * c.comp.a;
	return t;
}// Оператор умножения
Complex Complex::operator /(const Complex& c) {
	Complex t;
	t.comp.a = (comp.r * comp.a * c.comp.a + c.comp.r * comp.b * c.comp.b) / (comp.r * comp.a * comp.a + c.comp.r * comp.b * comp.b);
	t.comp.b = (comp.r * comp.b * c.comp.a - c.comp.r * comp.a * c.comp.b) / (comp.r * comp.a * comp.a + c.comp.r * comp.b * comp.b);
	return t;
}// Оператор деления
Complex Complex::operator -(const Complex& c) {
	Complex y;
	y.comp.a = comp.r * comp.a - c.comp.r * c.comp.a;
	y.comp.b = comp.r * comp.b - c.comp.r * c.comp.b;
	return y;
}// Оператор вычитания
void Complex::Display() {
	if (comp.b >= 0)
		cout << comp.a << "+" << comp.b << "i\n";
	else
		cout << comp.a << comp.b << "i\n";// Если мнимая часть больше 0
}// Метод вывода ответа на экран
Complex Complex::Read() {
	double x, y, z;
	cout << "Действительная часть: ";
	cin >> x;
	cout << "Мнимая часть:        : ";
	cin >> y;
	z = 1;
	Complex A = Complex(x, y, z);
	return A;
}// Метод для ввода данных с клавиатуры(алгебраическая форма)
Complex Complex::ReadTR() {
	double x, y, z, AB, AC, BC;
	cout << "1 сторона: ";
	cin >> AB;
	cout << "2 сторона: ";
	cin >> BC;
	z = sqrt(AB * AB + BC * BC);
	x = AB / z;
	y = BC / z;
	Complex A = Complex(x, y, z);
	return A;
}// Метод для ввода данных с клавиатуры(тригонометрическая форма)

//-----------------------------------------------------------
int chois() {
	int chois_1;
	cout << "     Операции комплексными числами\n";
	cout << " 1 - Сложение\n";
	cout << " 2 - Вычитание\n";
	cout << " 3 - Умножение\n";
	cout << " 4 - Деление\n";
	cout << "\n Выберите действие: \n";
	cin >> chois_1;
	while ((chois_1 < 0) || (chois_1 > 4)) {
		cout << "     !!!Не корректные данные!!!\n";
		cout << " Введите заново : ";
		cin >> chois_1;
	}// Условия корректного ввода для выбора варианта
	return chois_1;
}
void choise() {// Метод выбора варианта
	switch (chois()) {
	case 1: {// Вариант сложения комплексных чисел
		Complex a, b;
		double p;
		cout << "Выберите алгебраическую(1) или тригонометрическую(0) форму: ";
		cin >> p;
		if (p > 0) {
			cout << "Первое число:\n";
			a = a.Read();
			cout << "Второе число:\n";
			b = b.Read();
		}
		else
		{
			cout << "Первая сторона:\n";
			a = a.ReadTR();
			cout << "Вторая сторона:\n";
			b = b.ReadTR();
		};
		Complex c = a + b;
		c.Display();
		break;
	}
	case 2: {// Вариант вычитания комплексных чисел
		Complex a, b;
		double p;
		cout << "Выберите алгебраическую(1) или тригонометрическую(0) форму: ";
		cin >> p;
		if (p > 0) {
			cout << "Первое число:\n";
			a = a.Read();
			cout << "Второе число:\n";
			b = b.Read();
		}
		else
		{
			cout << "Первая сторона:\n";
			a = a.ReadTR();
			cout << "Вторая сторона:\n";
			b = b.ReadTR();
		};
		Complex c = a - b;
		c.Display();
		break;
	}
	case 3: {// Вариант умножения комплексных чисел
		Complex a, b;
		double p;
		cout << "Выберите алгебраическую(1) или тригонометрическую(0) форму: ";
		cin >> p;
		if (p > 0) {
			cout << "Первое число:\n";
			a = a.Read();
			cout << "Второе число:\n";
			b = b.Read();
		}
		else
		{
			cout << "Первая сторона:\n";
			a = a.ReadTR();
			cout << "Вторая сторона:\n";
			b = b.ReadTR();
		};
		Complex c = a * b;
		c.Display();
		break;
	}
	case 4: {// Вариант деления комплексных чисел
		Complex a, b;
		double p;
		cout << "При выборе алгебраической или тригонометрической формы и вводе:" << endl;
		cout << "первого числа = 1+2i и второго = 2+1i результат будет равен 0.8+0.6i" << endl;
		cout << "Выберите алгебраическую(1) или тригонометрическую(0) форму: ";
		cin >> p;
		if (p > 0) {
			cout << "Первое число:\n";
			a = a.Read();
			cout << "Второе число:\n";
			b = b.Read();
		}
		else
		{
			cout << "Первая сторона:\n";
			a = a.ReadTR();
			cout << "Вторая сторона:\n";
			b = b.ReadTR();
		};
		Complex c = a / b;
		c.Display();
		break;
	}
	default:break;
	}
}

int main()
{
	int m;
	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "Разработчик программы, Абсалямов Амир Ильясович, студент 2 курса, группа БИТ\n" << endl;
		cout << "Данная программа-проводник по программам из лабораторных работ" << endl;
		cout << "1 - Программа для вычисления факториала числа;" << endl;
		cout << "2 - Программа для вычисления смешанного произведения векторов;" << endl;
		cout << "3 - Программа для вычисления синуса методом разложения в ряд;" << endl;
		cout << "4 - Программа для реализация комплексных чисел в алгебраической и тригонометрической форме и основные операции с ними:\n    сложение, вычитание, умножение и деление;" << endl;
		cout << "5 - Для выхода из программы введите любой символ или 0:\n" << endl;
		cout << "Для выбора программы напишите ее порядковый номер:";
		cin >> m;
		system("cls");
		switch (m)
		{
		case 1:
		{
			int n, t;
			cout << "Программа для вычисления факториала." << endl;
			cout << "При вводе n = 3, факториал будет равен 6" << endl;
			cout << "Введите число n в промежутке от 0 до 170 для вычисления его факториала: ";
			do
			{
				cin >> n;
				if (n <= 170)
					cout << "Значение факториала равно " << obj.fact(n) << endl;
				else
				{
					cout << "Вы ввели неверное число. Повторите ввод:";
				}
			} while (n > 170);
			break;
		}
		case 2:
		{
			cout << "Программа для вычисления смешанного произведения векторов" << endl;
			cout << "При вводе координат первого вектора x = 1, y = 2, z = 3" << endl;
			cout << "При вводе координат второго вектора x = 3, y = 2, z = 1" << endl;
			cout << "Векторное произведение будет равно (-4, 8, -4)" << endl;
			cout << "Скалярное произведение будет равно (3, 4, 3)" << endl;
			int t;
			Vector a, b, c;
			string buffer1, buffer2, buffer3, buffer4, buffer5, buffer6;
			cout << "Введите значения x,y,z для первого вектора: " << endl;
			cin >> buffer1;
			replace(buffer1.begin(), buffer1.end(), ',', '.');
			stringstream ss1(buffer1);
			ss1 >> a.x;
			cin >> buffer2;
			replace(buffer2.begin(), buffer2.end(), ',', '.');
			stringstream ss2(buffer2);
			ss2 >> a.y;
			cin >> buffer3;
			replace(buffer3.begin(), buffer3.end(), ',', '.');
			stringstream ss3(buffer3);
			ss3 >> a.z;
			cout << "Введите значения x,y,z для второго вектора: " << endl;
			cin >> buffer4;
			replace(buffer4.begin(), buffer4.end(), ',', '.');
			stringstream ss4(buffer4);
			ss4 >> b.x;
			cin >> buffer5;
			replace(buffer5.begin(), buffer5.end(), ',', '.');
			stringstream ss5(buffer5);
			ss5 >> b.y;
			cin >> buffer6;
			replace(buffer6.begin(), buffer6.end(), ',', '.');
			stringstream ss6(buffer6);
			ss6 >> b.z;
			cout << "Векторное произведение [ab]=";
			a.vproiz(b).show();
			cout << "Скалярное произведение a*b=";
			a.sproiz(b).show();
			break;
		}
		case 3:
		{
			cout << "Программа для вычисления синуса методом разложения в ряд" << endl;
			cout << "При вводе x = 0.5 значение синуса будет равно 0,479426";
			sinus q;
			cout << "Введите значение x в промежутке от 0 до 1:";
			string buffer1;
			do
			{
				do
				{
					cin >> buffer1;
					replace(buffer1.begin(), buffer1.end(), ',', '.');
					stringstream ss1(buffer1);
					ss1 >> q.x;
					if (q.x >= 0 && q.x <= 1)
					{
						cout << "Значение синуса для ряда с 100 элементами равен:";
						cout << q.sin() << endl;
						double p;
						cout << "Если вы хотите увидеть ряд, то введите любое число больше 0:";
						cin >> p;
						if (p > 0) { cout << q.sin1() << endl; };
					}
					else
					{
						cout << "Вы ввели неправильное значение x. Введите повторно:";
					}
				} while (q.x > 1);
			} while (q.x < 0);
			break;
		}
		case 4:
		{
			cout << "Программа для реализация комплексных чисел в алгебраической и тригонометрической форме и основные операции с ними :\nсложение, вычитание, умножение и деление" << endl;
			setlocale(LC_ALL, "Russian");

			cout << " -------------------------------------------------------\n";
			choise();// Вызов функции для работы с операциями над комплексными числами

		}
		default:
			if (m > 4)
			{
				cout << "Такого номера программы нет." << endl;
			}
		}
		system("pause");
		system("cls");
	} while (m != 0);
}
