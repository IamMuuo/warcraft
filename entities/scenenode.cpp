#include "scenenode.hpp"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <utility>
#include <algorithm>

// Init the scene node 
SceneNode::SceneNode() {
  mParent = nullptr;
  mChildren.clear();
}

void SceneNode::attachChild(Ptr child) {
  child->mParent = this;
  mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node) {
  // Search for the requested element
  auto found = std::find_if(
      mChildren.begin(),mChildren.end(),
      [&](Ptr& p)->bool{return p.get() == &node;});

  //  Remove the found element from the list
  Ptr result = std::move(*found);
  result->mParent = nullptr;
  mChildren.erase(found);

  return result;
}

void SceneNode::draw(sf::RenderTarget& target,
    sf::RenderStates states) const
{
  states.transform *= getTransform();
}

void SceneNode::drawCurrent(sf::RenderTarget& target,
        sf::RenderStates states)const{
  // draw all the elements
  for(const Ptr& node : mChildren) {
    node->draw(target, states);
  }

}

