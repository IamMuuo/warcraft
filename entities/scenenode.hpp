#pragma once
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <memory>
#include <vector>
#include <SFML/Window.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable,
  private sf::NonCopyable
{
  public:
    typedef std::unique_ptr<SceneNode> Ptr;

    SceneNode();

    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);

  private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;

    virtual void draw(sf::RenderTarget& target,
        sf::RenderStates states)const;

    virtual void drawCurrent(sf::RenderTarget& target,
        sf::RenderStates states)const;

};
