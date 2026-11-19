#pragma once

#include <map>
#include <string>
#include <memory>


template<typename Resource, typename Identifier>
class ResourceHolder
{
private:
    std::map<Identifier, std::unique_ptr<Resource>> resourceMap_;

public:
    void loadResource(Identifer id, const std::string& filePath);

    Resource& getResource(Identifier id);

    const Resource& getResource(Identifier id) const;
};