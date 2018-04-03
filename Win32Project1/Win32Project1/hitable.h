#pragma once

#include <memory>
#include "vec3.h"
#include "material.h"

struct Ray;
struct HitInfos;

class Hitable
{
public:

    Hitable( std::shared_ptr< const Material > material_ )
        : material( material_ )
    { }

    virtual ~Hitable() = default;
    virtual bool Hit( const Ray & ray, float min_time, float max_time, HitInfos & hit_infos ) const = 0;

protected:

    std::shared_ptr< const Material > material;
};