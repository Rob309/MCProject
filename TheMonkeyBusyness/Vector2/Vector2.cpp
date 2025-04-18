#include "Vector2.h"
#include <cmath>
#include <stdexcept>
//#include "ConstantValues.h"

template class VECTOR2_API Vector2<float>;
template class VECTOR2_API Vector2<double>;
template class VECTOR2_API Vector2<long double>;

constexpr float kPi = 3.14159265358979323846f;
constexpr float kDefaultRotationOffset = 90.0f;

template <std::floating_point T>
Vector2<T>::Vector2(T x, T y) : x(x), y(y)
{}
template <std::floating_point T>
Vector2<T> Vector2<T>::Normalize(const Vector2 vector2)
{
	T magnitude = std::sqrt(pow(vector2.x, 2) + pow(vector2.y, 2));
	if (magnitude == 0) return Vector2();
	return Vector2(vector2.x / magnitude, vector2.y / magnitude);
}
template <std::floating_point T>
void Vector2<T>::Normalize()
{
	T magnitude = std::sqrt(pow(this->x, 2) + pow(this->y, 2));
	if (!magnitude == 0)  (*this /= magnitude);
}
template <std::floating_point T>
Vector2<T> Vector2<T>::operator*(const Vector2& vector) const
{
	return Vector2(this->x * vector.x, this->y * vector.y);
}
template <std::floating_point T>
Vector2<T> Vector2<T>::operator*(const T scalar) const
{
	return Vector2(this->x * scalar, this->y * scalar);
}
template <std::floating_point T>
Vector2<T>& Vector2<T>::operator*=(const T scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	return *this;
}

template <std::floating_point T>
Vector2<T> Vector2<T>::operator/(const T scalar) const {
	if (scalar != 0) {
		return Vector2(this->x / scalar, this->y / scalar);
	}
	else {
		// Throw an exception if division by zero occurs
		throw std::invalid_argument("Division by zero in Vector2::operator/");
	}

}
template <std::floating_point T>
Vector2<T>& Vector2<T>::operator/=(const T scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	return *this;
}
template <std::floating_point T>
Vector2<T> Vector2<T>::operator+(const Vector2& vector) const
{
	return Vector2(this->x + vector.x, this->y + vector.y);
}
template <std::floating_point T>
Vector2<T>& Vector2<T>::operator+=(const Vector2& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	return *this; // Return the current object by reference
}
template <std::floating_point T>
Vector2<T> Vector2<T>::operator-(const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}
template <std::floating_point T>
bool Vector2<T>::operator==(const Vector2& other) const
{
	return this->x == other.x && this->y == other.y;
}
template <std::floating_point T>
bool Vector2<T>::operator!=(const Vector2& other) const
{
	return !(*this == other);
}

template <std::floating_point T>
T Vector2<T>::GetAngleFromNormalizedVector() const
{
	T angleInRadians = atan2(this->y, this->x);

	// Convert radians to degrees
	T angleInDegrees = angleInRadians * (180.0f /kPi);

	// Adjust the angle: since (0, -1) is 0 degrees, we need to shift by 90 degrees
	angleInDegrees = fmod(angleInDegrees + kDefaultRotationOffset, 360.0f);

	// If angle is negative, make it positive
	if (angleInDegrees < 0) {
		angleInDegrees += 360.0f;
	}

	return angleInDegrees;
}
template <std::floating_point T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& vector)
{
	os << "(" << vector.x << ", " << vector.y << ")";
	return os;
}
