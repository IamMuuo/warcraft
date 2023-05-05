/*
 * This file is part of project Warcraft
 * Cantains the Resource class identifier implementation system
 * Author Erick Muuo
 * Copyright (c) 2023 Erick. All Rights Reserved.
 */

#pragma once

#include <memory>
#include <map>


template<typename Resource, typename Identifier>
class ResourceHolder {

  public:
    void load(Identifier id, const std::string& filename);

    Resource& get(Identifier id);
    const Resource& get(Identifier id)const;

  private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};
