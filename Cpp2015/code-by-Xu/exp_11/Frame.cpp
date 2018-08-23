#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <iomanip>

#include <cstdlib>

#include "Array.h"

using namespace std;

class Shape {
public:
	Shape(int classId, double unitPrice) :
			classId(classId), unitPrice(unitPrice) {
	}
	virtual double getCircumference() = 0;
	virtual void showInfo() = 0;

	virtual ~Shape() {
	}
	bool operator >(Shape & shape);
	int getClassId() {
		return classId;
	}
	double getUnitPrice() const {
		return unitPrice;
	}
	void setUnitPrice(double unitPrice) {
		this->unitPrice = unitPrice;
	}
private:
	int classId;
	double unitPrice;
};

bool Shape::operator >(Shape & shape) {
	return (getCircumference() > shape.getCircumference());
}

class Circle: public Shape {
public:
	Circle(double unitPrice = 0, int classId = 1) :
			Shape(classId, unitPrice) {
	}
	Circle(double radius, double unitPrice, int classId = 1) : // 圆形的classId默认为1
			Shape(classId, unitPrice), radius(radius) {
	}

	static Shape * createCircle() {
		cout << "请输入圆形的半径和单价：";
		double radius, unitPrice;
		cin >> radius >> unitPrice;
		return new Circle(radius, unitPrice);
	}

	double getCircumference() {
		return 2 * radius * PI;
	}

	void showInfo() {
		cout << getClassId() << ". 圆形，半径" << radius << "，周长" << getCircumference() << ", 单价" << getUnitPrice() << endl;
	}

private:
	double radius;
	static const double PI = 3.1415926;
};

class Rectangle: public Shape {
public:
	Rectangle(double unitPrice = 0, int classId = 2) :
			Shape(classId, unitPrice) {
	}
	Rectangle(double length, double width, double unitPrice, int classId = 2) : // 长方形的classId默认为2
			Shape(classId, unitPrice), length(length), width(width) {
	}

	static Shape * createRectangle() {
		cout << "请输入长方形的长、宽和单价：";
		double length, width, unitPrice;
		cin >> length >> width >> unitPrice;
		return new Rectangle(length, width, unitPrice);
	}

	double getCircumference() {
		return 2 * (length + width);
	}

	void showInfo() {
		cout << getClassId() << ". 长方形，长" << length << "，宽" << width << "，周长" << getCircumference() << ", 单价" << getUnitPrice() << endl;
	}

private:
	double length;
	double width;
};

class Square: public Rectangle {
public:
	Square(double unitPrice = 0, int classId = 4) :
			Rectangle(unitPrice, classId) {
	}
	Square(double edge, double unitPrice, int classId = 4) : // 正方形的classId默认为4
			Rectangle(edge, edge, unitPrice, classId), edge(edge) {
	}

	static Shape * createSquare() {
		cout << "请输入正方形的边长和单价：";
		double edge, unitPrice;
		cin >> edge >> unitPrice;
		return new Square(edge, unitPrice);
	}

	void showInfo() {
		cout << getClassId() << ". 正方形，边长" << edge << "，周长" << getCircumference() << ", 单价" << getUnitPrice() << endl;
	}

private:
	double edge;
};

class RightTriangle: public Shape {
public:
	RightTriangle(double unitPrice = 0, int classId = 3) :
			Shape(classId, unitPrice) {
	}
	RightTriangle(double edge1, double edge2, double unitPrice, int classId = 3) : // 直角三角形的classId默认为3
			Shape(classId, unitPrice), edge1(edge1), edge2(edge2) {
	}

	static Shape * createRightTriangle() {
		cout << "请输入直角三角形的两条边长和单价：";
		double edge1, edge2, unitPrice;
		cin >> edge1 >> edge2 >> unitPrice;
		return new RightTriangle(edge1, edge2, unitPrice);
	}

	double getCircumference() {
		return edge1 + edge2 + sqrt(edge1 * edge1 + edge2 * edge2);
	}

	void showInfo() {
		cout << getClassId() << ". 直角三角形，直角边" << edge1 << "，直角边" << edge2 << "，周长" << getCircumference() << ", 单价" << getUnitPrice() << endl;
	}

private:
	double edge1;
	double edge2;
};

class FileNotFoundException: public runtime_error {
public:
	FileNotFoundException(const string& what_arg) :
			runtime_error(what_arg) {
	}
};

void insertSort(Array<Shape *> &shapes, int index, Shape * ptr) { // 将新创建的形状ptr插入到动态数组shapes中
	int size = shapes.getSize();
	int boundary = 0;

	for (; boundary < index; boundary++) {
		if (*shapes[boundary] > *ptr)
			break;
	}

	for (int i = size - 1; i > boundary; i--)
		shapes[i] = shapes[i - 1];
	shapes[boundary] = ptr;
}

int createShapes(const char * fileName, Array<Shape *> &shapes) {
	int shapeNums = 0;
	int classId;
	int preSize = shapes.getSize();
	const double value = 3.0;
	string line, shapeName;
	double unitPrice;

	cout << "从文件" << fileName << "中读入数据，生成框架产品的目录清单" << endl;

	ifstream fileStream(fileName);

	if (!fileStream) {
		ostringstream message;
		message << "不能打开文件" << fileName << "，请确认文件是否存在";
		throw FileNotFoundException(message.str());
	}

	while (getline(fileStream, line)) { // 从文本文件中读入1行
		istringstream strStream(line);
		Shape *ptr = NULL;

		strStream >> classId;
		string str1, str2;
		strStream >> str1 >> str2 >> unitPrice;
		// 因为每行的形如: 1. Circle, 4.0，语句执行之后，str1的值是".", str2的值是"Circle,", unitPrice的值是4.0
		switch (classId) {
		case 1:
			ptr = new Circle(value, unitPrice);
			break;
		case 2:
			ptr = new Rectangle(value, value, unitPrice);
			break;
		case 3:
			ptr = new RightTriangle(value, value, unitPrice);
			break;
		case 4:
			ptr = new Square(value, unitPrice);
			break;
		default:
			cout << "错误的classId，请检查文件的内容" << endl;
			break;
		}

		insertSort(shapes, shapeNums, ptr); // 执行插入排序
		shapeNums++;

		if (shapeNums >= preSize) { // 调整动态数组的大小
			preSize *= 2;
			shapes.resize(preSize);
		}
	}

	for (int i = 0; i < shapeNums; i++)
		shapes[i]->showInfo();

	return shapeNums;
}

void outputBinaryFiles(Array<Shape *> &shapes, int shapeNums) {
	cout << endl << "将动态数组中的内容分别写入到二进制文件中" << endl;

	ofstream circleFile("Circle.dat", ios_base::out | ios_base::binary);
	ofstream RectangleFile("Rectangle.dat", ios_base::out | ios_base::binary);
	ofstream rightangleFile("Rightangle.dat", ios_base::out | ios_base::binary);
	ofstream squareFile("Square.dat", ios_base::out | ios_base::binary);

	for (int i = 0; i < shapeNums; i++) {
		int classId = shapes[i]->getClassId();
		switch (classId) {
		case 1: {
			Circle *ptr = dynamic_cast<Circle *>(shapes[i]);
			circleFile.write(reinterpret_cast<char *>(ptr), sizeof(*ptr));
			// shapes[i]->showInfo();
			// cout << "size = " << sizeof(*ptr) << endl;
			break;
		}
		case 2: {
			Rectangle *ptr = dynamic_cast<Rectangle *>(shapes[i]);
			RectangleFile.write(reinterpret_cast<char *>(ptr), sizeof(*ptr));
			break;
		}
		case 3: {
			RightTriangle *ptr = dynamic_cast<RightTriangle *>(shapes[i]);
			rightangleFile.write(reinterpret_cast<char *>(ptr), sizeof(*ptr));
			break;
		}
		case 4: {
			Square *ptr = dynamic_cast<Square *>(shapes[i]);
			squareFile.write(reinterpret_cast<char *>(ptr), sizeof(*ptr));
			break;
		}
		}
	}
	circleFile.close();
	cout << "文件写入操作完成" << endl;
}

void readBinaryFiles() {
	cout << endl << "从二进制文件中读取数据" << endl;

	ifstream circleFile("Circle.dat", ios_base::in | ios_base::binary);
	ifstream RectangleFile("Rectangle.dat", ios_base::in | ios_base::binary);
	ifstream rightangleFile("Rightangle.dat", ios_base::in | ios_base::binary);
	ifstream squareFile("Square.dat", ios_base::in | ios_base::binary);

	Circle circle;
	while (circleFile.read(reinterpret_cast<char *>(&circle), sizeof(circle))) {
		//circleFile.read(reinterpret_cast<char *>(&circle), sizeof(circle));
		circle.showInfo();
	}
	circleFile.close();

	Rectangle rectangle;
	while (RectangleFile.read(reinterpret_cast<char *>(&rectangle), sizeof(rectangle))) {
		rectangle.showInfo();
	}
	RectangleFile.close();

	RightTriangle right;
	while (rightangleFile.read(reinterpret_cast<char *>(&right), sizeof(right))) {
		right.showInfo();
	}
	rightangleFile.close();

	Square square;
	while (squareFile.read(reinterpret_cast<char *>(&square), sizeof(square))) {
		square.showInfo();
	}
	squareFile.close();

	cout << "文件读取操作完成" << endl;
}

int main() {
	int preSize = 2; // 动态数组的初始大小
	Array<Shape *> shapes(preSize);
	for (int i = 0; i < preSize; i++) // 要将shapes中的指针元素初始化为NULL，否则有可能是“野指针”
		shapes[i] = NULL;

	int shapeNums = 0;
	try {
		shapeNums = createShapes("Shapes.txt", shapes);
	} catch (FileNotFoundException &e) {
		cout << e.what() << endl;
		exit(-1);
	}

	outputBinaryFiles(shapes, shapeNums);
	readBinaryFiles();

	return 0;
}
