#include "ResourceHolder.h"
#include <stdexcept>
#include <utility>


template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::loadResource(Identifier id, const std::string& filePath)
{
    auto resource = std::make_unique<Resource>();

    if (!resource->loadFromFile(filePath))
        throw std::runtime_error("Failed to load resource from " + filePath);

    const auto [it, inserted] = resourceMap_.emplace(id, std::move(resource));
    if (!inserted)
        throw std::runtime_error("Resource ID is already in use");
}

template<typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::getResource(Identifier id)
{
    return *resourceMap_.at(id);
}

template<typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::getResource(Identifier id) const
{
    return *resourceMap_.at(id);
}