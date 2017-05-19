#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "header.h"
#include "Vec3.h"
#pragma once
class Shape {
public:
	Shape(){
	}
	Shape(Shape& tempS){
		velocity = tempS.velocity;

	}
	virtual ~Shape(){
	}
	virtual void move() = 0;
	virtual void draw() = 0;
	Vec3 center;
	Vec3 velocity;
};

class Color{
public:
	Color(){

	}
	Color(Color& c){
		this->rgb = c.rgb;
	}
	virtual ~Color(){

	}
	void setRGB(float r, float g, float b){
		rgb[0] = r;
		rgb[1] = g;
		rgb[2] = b;
	}

	Vec3 rgb;
};
void initShape(int gamelevel);
#endif