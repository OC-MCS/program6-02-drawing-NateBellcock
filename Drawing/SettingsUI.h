#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	SettingsMgr *set;
	CircleShape red, Yellow, blue;
	CircleShape circle;
	RectangleShape square;
public:
	SettingsUI(SettingsMgr *mgr)
	{
		set = mgr;
		red.setRadius(20);
		red.setPosition(50, 75);
		red.setOutlineColor(Color::Red);
		red.setOutlineThickness(3);
		Yellow.setRadius(20);
		Yellow.setPosition(50, 125);
		Yellow.setOutlineColor(Color::Yellow);
		Yellow.setOutlineThickness(3);
		blue.setRadius(20);
		blue.setPosition(50, 175);
		blue.setOutlineColor(Color::Blue);
		blue.setOutlineThickness(3);
		circle.setRadius(20);
		circle.setPosition(50, 350);
		circle.setOutlineColor(Color::White);
		circle.setOutlineThickness(3);
		square.setSize(Vector2f(40, 40));
		square.setPosition(50, 400);
		square.setOutlineColor(Color::White);
		square.setOutlineThickness(3);

	}
	void handleMouseUp(Vector2f mouse)
	{
		if (red.getGlobalBounds().contains(mouse))
		{
			set->setColor(Color::Red);
		}
		else if(Yellow.getGlobalBounds().contains(mouse))
		{
			set->setColor(Color::Yellow);
		}
		else if (blue.getGlobalBounds().contains(mouse))
		{
			set->setColor(Color::Blue);
		}
		else if (circle.getGlobalBounds().contains(mouse))
		{
			set->setShape(CIRCLE);
		}
		else if (square.getGlobalBounds().contains(mouse))
		{
			set->setShape(SQUARE);
		}

	}

	void draw(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		// title
		Text title("Drawing Color", font, 25);
		title.setPosition(30, 25);
		win.draw(title);
		red.setFillColor(Color::Transparent);
		Yellow.setFillColor(Color::Transparent);
		blue.setFillColor(Color::Transparent);
		if (set->getCurColor() == Color::Red)
		{
			red.setFillColor(Color::Red);
		}
		else if (set->getCurColor() == Color::Yellow)
		{
			Yellow.setFillColor(Color::Yellow);
		}
		else if (set->getCurColor() == Color::Blue)
		{
			blue.setFillColor(Color::Blue);
		}
		circle.setFillColor(Color::Transparent);
		square.setFillColor(Color::Transparent);
		if (set->getCurShape() == CIRCLE)
		{
			circle.setFillColor(Color::White);
		}
		else if (set->getCurShape() == SQUARE)
		{
			square.setFillColor(Color::White);
		}
		Text title2("Drawing Shape", font, 25);
		title2.setPosition(30, 300);
		win.draw(title2);
		win.draw(red);
		win.draw(Yellow);
		win.draw(blue);
		win.draw(circle);
		win.draw(square);
	}

};

