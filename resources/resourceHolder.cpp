#include "resourceHolder.hpp"
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id,
    const std::string& filename) {
  std::unique_ptr<Resource> resource(new Resource());

  if(!resource.loadFromFile(filename)) {
    throw  std::runtime_error("ResourceHolder: Couldn't open"
        + filename);
  }

  mResourceMap.insert(std::make_pair(id, std::move(resource)));
}

template<typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) {
  auto found = mResourceMap.find(id);

  return *found->second;
}

template<typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const {
  auto found = mResourceMap.find(id);

  return *found->second;
}
