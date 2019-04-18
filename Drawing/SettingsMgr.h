#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	ShapeEnum shapSeting;
	Color colorSeting;
	
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		shapSeting = startingShape;
		colorSeting = startingColor;
	}

	Color getCurColor()
	{
		return colorSeting;
	}


	ShapeEnum getCurShape()
	{
		return shapSeting;
	}

	void setColor(Color c)
	{
		colorSeting = c;
	}

	void setShape(ShapeEnum s)
	{
		shapSeting = s;
	}

	//======================================================
	// fileIn reads in from file
	// parameters: fstreeam &f is the the file straem
	// return type: void
	//======================================================
	void fileIn(fstream &f)
	{
		f.read(reinterpret_cast<char*>(&shapSeting), sizeof(shapSeting));
		unsigned int temp;
		f.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		colorSeting = Color(temp);
	}

	//======================================================
	// fileout reads out to file
	// parameters: fstreeam &f is the the file straem
	// return type: void
	//======================================================
	void fileOut(fstream &f)
	{
		f.write(reinterpret_cast<char*>(&shapSeting), sizeof(shapSeting));
		unsigned int temp = colorSeting.toInteger();
		f.write(reinterpret_cast<char*>(&temp), sizeof(temp));
	}

};
