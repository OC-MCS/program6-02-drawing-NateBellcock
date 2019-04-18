#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct MyShape
{
	ShapeEnum shape;
	float x, y;
	unsigned int color;
};
// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
public:
	virtual void draw(RenderWindow& win) = 0;
	virtual MyShape getFileRecord() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape
class Square : public DrawingShape
{
private:
	RectangleShape r;
public:
	Square(Color co, Vector2f p)
	{
		r.setFillColor(co);
		r.setSize(Vector2f(10, 10));
		r.setPosition(p);
	}
	void draw(RenderWindow& win)
	{
		win.draw(r);
	}
	MyShape getFileRecord()
	{
		return { SQUARE, r.getPosition().x, r.getPosition().y, r.getFillColor().toInteger() };
	}

};

class Circle : public DrawingShape
{
private:
	CircleShape c;
public:
	Circle(Color co, Vector2f p)
	{
		c.setFillColor(co);
		c.setRadius(5);
		c.setPosition(p);
	}
	void draw(RenderWindow& win)
	{
		win.draw(c);

	}
	MyShape getFileRecord()
	{
		return { CIRCLE, c.getPosition().x, c.getPosition().y, c.getFillColor().toInteger() };
	}

};


