#pragma once

#include "hitable.h"

#include "json.hpp"
using nlohmann::json;

#include "Vec3.h"

struct Ray;
struct HitInfos;
class aabb;

class Sphere : public Hitable
{
public:

    Sphere( const Vec3 & center_, float radius_, std::shared_ptr< const Material > material_ );
    // Sphere( const json & sphere_json );

    bool Hit( const Ray & ray, float min_time, float max_time, HitInfos & hit_infos ) const;
    bool GetBoundingBox(aabb & box) const;

    Vec3 center;
    float radius;

private:

    void FillHitInfos( HitInfos & hit_infos, const Ray & ray, float time ) const;

    float squaredRadius;
    float invRadius;
};