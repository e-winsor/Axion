#pragma once

#include "axion/precision.h"

namespace axion
{
  class Vec3
  {
   public:
    // Member variables
    real x;
    real y;
    real z;

    // Constructors
    Vec3() = default;
    constexpr Vec3(real x, real y, real z) noexcept;

    // Arithmetic operators
    Vec3 operator+(const Vec3& rhs) const noexcept;
    Vec3 operator-(const Vec3& rhs) const noexcept;
    Vec3 operator*(real scalar) const noexcept;
    Vec3 operator/(real scalar) const noexcept;

    // Compound assignment operators
    Vec3& operator+=(const Vec3& rhs) noexcept;
    Vec3& operator-=(const Vec3& rhs) noexcept;
    Vec3& operator*=(real scalar) noexcept;
    Vec3& operator/=(real scalar) noexcept;

    // Vector operations
    real dot(const Vec3& rhs) const noexcept;
    Vec3 cross(const Vec3& rhs) const noexcept;
    real magnitudeSquared() const noexcept;
    real magnitude() const noexcept;

    Vec3& normalize() noexcept;
    Vec3 normalized() const noexcept;

    Vec3 distanceTo(const Vec3& other) const noexcept;

    bool isZero() const noexcept;
    bool isNormalized() const noexcept;

    // Useful vectors
    static Vec3 zero() noexcept;
    static Vec3 one() noexcept;
    static Vec3 unitX() noexcept;
    static Vec3 unitY() noexcept;
    static Vec3 unitZ() noexcept;
  };
}
