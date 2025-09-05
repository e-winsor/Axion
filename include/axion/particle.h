#include "Vec3.h"
#include "SDL3/SDL.h"

namespace axion
{
  class Particle
  {
   public:
    Vec3 position;
    Vec3 velocity;
    Vec3 acceleration;
    real mass;
    Vec3 forceAccum;

    Particle() = default;

    void clearForces()
    {
      forceAccum = Vec3(0.0f, 0.0f, 0.0f);
    }

    void addForce(const Vec3 &force)
    {
      forceAccum += force;
    }
    
    void updateParticle(const real deltaTime)
    {
      acceleration = forceAccum * (1 / mass);
      velocity += acceleration * deltaTime;
      position += velocity * deltaTime;
      // clearForces();
    }

    void draw(SDL_Renderer* renderer, const real radius) const
    {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int width = 0; width < radius * 2; width++)
      {
        for (int height = 0; height < radius * 2; height++)
        {
          int deltaX = radius - width;
          int deltaY = radius - height;
          if (((deltaX * deltaX) + (deltaY * deltaY)) <= (radius * radius))
          {
            SDL_RenderPoint(renderer, position.x + deltaX, position.y + deltaY);
          }
        }
      }
    }

  };
}
