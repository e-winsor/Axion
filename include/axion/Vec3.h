#pragma once

#include "axion/precision.h"

namespace axion
{
  class Vec3
  {
   public:
    // components of the vector

    real x;
    real y;
    real z;



    // constructors

    Vec3() = default;

    Vec3(const real x, const real y, const real z)
        : x(x), y(y), z(z)
    {
    }



    // operator ovverides for vector maths
    
    Vec3 operator+(const Vec3 &vector) const
    {
      return Vec3(x + vector.x, y + vector.y, z + vector.z);
    }

    Vec3 operator-(const Vec3 &vector) const
    {
      return Vec3(x - vector.x, y - vector.y, z - vector.z);
    }

    Vec3 operator*(const real &scalar) const
    {
      return Vec3(x * scalar, y * scalar, z * scalar);
    }

    Vec3 operator/(const real &scalar) const
    {
      return Vec3(x / scalar, y / scalar, z / scalar);
    }

    void operator+=(const Vec3 &vector)
    {
      x += vector.x;
      y += vector.y;
      z += vector.z;
    }

    void operator-=(const Vec3 &vector)
    {
      x -= vector.x;
      y -= vector.y;
      z -= vector.z;
 
    }

    void operator*=(const real &scalar)
    {
      x *= scalar;
      y *= scalar;
      z *= scalar;
    }

    void operator/=(const real &scalar)
    {
      x /= scalar;
      y /= scalar;
      z *= scalar;
    }



    // vector function

    real scalarProduct(const Vec3 &vector) const
    {
      return((x * vector.x) + (y * vector.y) + (z * vector.z));
    }

    Vec3 vectorProduct(const Vec3 &vector) const
    {
      return Vec3((y * vector.z) - (z * vector.y),
                 (z * vector.x) - (x * vector.z),
                 (x * vector.y) - (y * vector.x));
    }

    real magnitudeSquared() const
    {
      return ((x * x) + (y * y) + (z * z));
    }

    real magnitude() const
    {
      return (sqrtf(magnitudeSquared()));
    }

    void normalize()
    {
      real size {magnitude()};
      *this *= static_cast<real>(1) / size;
    }

    Vec3 distance(const Vec3 &vector) const
    {
      return Vec3(vector.x - x,
                  vector.y - y,
                  vector.z - z);
    }
  };
}
