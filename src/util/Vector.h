#pragma once
template<class T> struct Vector {
	T x;
	T y;

	Vector(const T & x, const T & y) : x(x), y(y) {}
	Vector(const Vector<T> & other) : x(other.x), y(other.y) {}
	Vector() : Vector(0, 0) {}

	void set(const T & x, const T & y) {
		this->x = x;
		this->y = y;
	}

	Vector<T> & operator=(const Vector<T> & other) {
		this->x = other.x;
		this->y = other.y;
		return *this;
	}

	Vector<T> & operator+=(const Vector<T> & offset) {
		this->x += offset.x;
		this->y += offset.y;
		return *this;
	}

	Vector<T> operator+(const Vector<T> & offset) const {
		return Vector(this->x + offset.x, this->y + offset.y);
	}

	Vector<T> operator-(const Vector<T> & offset) const {
		return Vector(this->x - offset.x, this->y - offset.y);
	}

	float length() const {
		return sqrtf(x*x + y*y);
	}
};

