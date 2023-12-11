#ifndef HITTABLE_H
#define HITTABLE_H

#include "commons.hpp"

/// @brief Class for recording hits and deciding the surface side.
class hit_record {
  public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    /// @brief Method for deciding and storing which side of the surface the ray is on.
    /// @param r Ray.
    /// @param outward_normal Normal that points outwards the surface.
    void set_face_normal(const ray& r, const vec3& outward_normal) {
        // NOTE: the parameter `outward_normal` is assumed to have unit length.
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

/// @brief Base class for hittable objects.
class hittable {
    public:
        virtual ~hittable() = default;

        /// @brief Abstract method for deciding a hit.
        /// @param r Ray.
        /// @param ray_t Valid ray interval.
        /// @param rec Hit record. 
        /// @return True if the ray hits the object or false if it doesn't.
        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif