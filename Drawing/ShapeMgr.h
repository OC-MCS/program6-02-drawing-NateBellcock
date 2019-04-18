#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> v;
	
public:
	//======================================================
	// deflet constrtor: 
	// parameters: none
	//======================================================
	ShapeMgr()
	{
		
	}
	//======================================================
	// addShape add a shape to the vector
	// parameters: pos postion (x,y) whchShape is what shape we are adding color is the color of the shape
	// return type: void
	//======================================================
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == SQUARE)
		{
			v.push_back(new Square(color, pos));
		}
		else
		{
			v.push_back(new Circle(color, pos));
		}
	}

	//======================================================
	// getList gives you the vector
	// parameters: none
	// return type: vector<DrawingShape*>
	//======================================================
	const vector<DrawingShape*>& getList()
	{
		return v;
	}

	//======================================================
	// fileIn reads in from file
	// parameters: fstreeam &f is the the file straem
	// return type: void
	//======================================================
	void fileIn(fstream & f)
	{
		MyShape temp;
		while (f.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			addShape(Vector2f(temp.x, temp.y), temp.shape, Color(temp.color));
		}
	}

	//======================================================
	// fileout reads out to file
	// parameters: fstreeam &f is the the file straem
	// return type: void
	//======================================================
	void fileOut(fstream & f)
	{
		
		for (int i =0; i < v.size();i++)
		{
			f.write(reinterpret_cast<char*>(&v[i]->getFileRecord()), sizeof(MyShape));
		}
	}
	
};
