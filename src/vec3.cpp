#include "axion/vec3.h"

namespace axion
{
  // Constructor
  constexpr Vec3::Vec3(real x, real y, real z) noexcept
    : x(x), y(y), z(z)
  {
  }

  // Arithmetic operators
  Vec3 Vec3::operator+(const Vec3& rhs) const noexcept
  {
    return {x + rhs.x, y + rhs.y, z + rhs.z};
  }

  Vec3 Vec3::operator-(const Vec3& rhs) const noexcept
  {
    return {x - rhs.x, y - rhs.y, z - rhs.z};
  }

  Vec3 Vec3::operator*(const real scalar) const noexcept
  {
    return {x * scalar, y * scalar, z * scalar};
  }

  Vec3 Vec3::operator/(const real scalar) const noexcept
  {
    return {x / scalar, y / scalar, z / scalar};
  }

  Vec3& Vec3::operator+=(const Vec3& rhs) noexcept
  {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

  Vec3& Vec3::operator-=(const Vec3& rhs) noexcept
  {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }

  Vec3& Vec3::operator*=(const real scalar) noexcept
  {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
  }

  Vec3& Vec3::operator/=(const real scalar) noexcept
  {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
  }

  // Vector operations
  real Vec3::dot(const Vec3& rhs) const noexcept
  {
    return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z));
  }
    
  Vec3 Vec3::cross(const Vec3& rhs) const noexcept
  {
    return {
      (y * rhs.z) - (z * rhs.y),
      (z * rhs.x) - (x * rhs.z),
      (x * rhs.y) - (y * rhs.x)
    };
  }

  real Vec3::magnitudeSquared() const noexcept
  {
    return ((x * x) + (y * y) + (z * z));
  }

  real Vec3::magnitude() const noexcept
  {
    return real_sqrt(magnitudeSquared());
  }

  Vec3& Vec3::normalize() noexcept
  {
    const real mag {magnitude()};
    if (mag > static_cast<real>(0))
    {
      *this /= mag;
    }
  }

  Vec3 Vec3::normalized() const noexcept
  {
    Vec3 result {*this};
    result.normalize();
    return result;
  }

  Vec3 Vec3::distanceTo(const Vec3& other) const noexcept
  {
    return{other.x - x, other.y - y, other.z - z};
  }

  // Utility funcitons
  bool Vec3::isZero() const noexcept
  {
    return x == static_cast<real>(0) &&
           y == static_cast<real>(0) &&
           z == static_cast<real>(0);
  }

  bool Vec3::isNormalized() const noexcept
  {
    constexpr real tolerance {static_cast<real>(1e-6)};
    const real magSq {magnitudeSquared()};
    return std::abs(magSq - static_cast<real>(1)) < tolerance;
  }

  // Useful vectors
  Vec3 Vec3::zero() noexcept
  {
    return {0, 0, 0};
  }

  Vec3 Vec3::one() noexcept
  {
    return {1, 1, 1};
  }

  Vec3 Vec3::unitX() noexcept
  {
    return {1, 0, 0};
  }

  Vec3 Vec3::unitY() noexcept
  {
    return {0, 1, 0};
  }

  Vec3 Vec3::unitZ() noexcept
  {
    return {0, 0, 1};
  }
}
