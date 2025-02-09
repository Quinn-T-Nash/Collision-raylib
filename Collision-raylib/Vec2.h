#ifndef VEC2_H
#define VEC2_H


template <typename T>
class Vec2
{
public:
	Vec2() = default;

	Vec2(T x, T y) : x(x), y(y) {}

    // Add getters for x and y components
    T getX() const { return x; }
    T getY() const { return y; }

    // Add basic vector operations
    Vec2& operator=(const Vec2& rhs) {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }

    Vec2 operator+(const Vec2& rhs) const {
        return Vec2(x + rhs.x, y + rhs.y);
    }

    Vec2 operator-(const Vec2& rhs) const {
        return Vec2(x - rhs.x, y - rhs.y);
    }

    Vec2 operator*(T scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 operator/(T scalar) const {
        return Vec2(x / scalar, y / scalar);
    }

private:
	T x;
	T y;

};

#endif