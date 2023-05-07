#include "entity.hpp"


class Aircraft : public Entity
{
  public:
    enum Type {
      Eagle,
      Raptor,
    };

    explicit Aircraft(Type type);

  private:
    Type mType;
};
