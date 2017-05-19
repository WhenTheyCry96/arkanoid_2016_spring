#ifndef VEC3_H_
#define VEC3_H_

#include "header.h"
#pragma once

class Vec3{
public:
	Vec3(){ x = y = z = 0; }
	Vec3(float a, float b, float c){
		x = a; y = b; z = c;
	}
	Vec3 operator=(const Vec3 &a) {
		x = a.x;
		y = a.y;
		z = a.z;
		return Vec3(a.x, a.y, a.z);
	}
	Vec3 operator+(const Vec3 &a) {
		return Vec3(x + a.x, y + a.y, z + a.z);
	}
	Vec3 operator-(const Vec3 &a) {
		return Vec3(x - a.x, y - a.y, z - a.z);
	}
	Vec3 operator+=(const Vec3 &a) {
		Vec3 temp(x, y, z);
		x += a.x;
		y += a.y;
		z += a.z;
		return Vec3(x, y, z);
	}
	Vec3 operator-=(const Vec3 &a) {
		Vec3 temp(x, y, z);
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return Vec3(x, y, z);
	}
	Vec3 operator/(float a) {
		Vec3 temp;
		temp[0] = x;
		temp[1] = y;
		temp[2] = z;
		for (int i = 0; i < 3; i++) {
			temp[i] /= a;
		}
		return temp;
	}
	Vec3 operator*(float a) {
		Vec3 temp;
		temp[0] = x;
		temp[1] = y;
		temp[2] = z;
		for (int i = 0; i < 3; i++) {
			temp[i] *= a;
		}
		return temp;
	}
	float operator*(const Vec3 &a) {
		Vec3 temp(x, y, z);
		x *= a.x;
		y *= a.y;
		z *= a.z;
		float resultf = x + y + z;
		return resultf;
	}
	Vec3 operator/(const Vec3 &a) {
		return Vec3(x / a.x, y / a.y, z / a.z);
	}
	float& operator[](int a) {
		if (a == 0)
			return x;
		else if (a == 1)
			return y;
		else if (a == 2)
			return z;
	}

	float x, y, z;
};
inline Vec3 operator*(float a, Vec3 b) {
	return Vec3(a*b.x, a*b.y, a*b.z);
}
#endif