#pragma once

#include "Resource.hpp"

class ResourceManager
{
    public:
        ResourceManager() : resource(new Resource()){}
        
        ResourceManager(const ResourceManager& r) : resource(new Resource(*(r.resource))){}

        ResourceManager& operator=(const ResourceManager& r)
        {
            if (this != &r) {
                delete resource;
                resource = new Resource(*(r.resource));
            }
            return *this;
        }

        ResourceManager(ResourceManager&& r) noexcept : resource(r.resource){
            r.resource = nullptr;
        }

        ResourceManager& operator=(ResourceManager&& r) noexcept
        {
            if (this != &r) {
                delete resource;
                resource = new Resource(*(r.resource));
                r.resource = nullptr;
            }
            return *this;
        }

        ~ResourceManager()
        {
            delete resource;
        }

        double get()
        {
            return resource->get();
        }

    private:
        Resource* resource;
};
