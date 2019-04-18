#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape canvas;
public:
	DrawingUI(Vector2f p)
	{
		canvas.setPosition(p);
		canvas.setSize(Vector2f(550, 500));
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		win.draw(canvas);
		vector<DrawingShape*> v = mgr->getList();
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->draw(win);
		}
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		return canvas.getGlobalBounds().contains(mousePos) && canvas.getGlobalBounds().contains(mousePos + Vector2f(20, 20));
	}

};

