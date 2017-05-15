#pragma once
#include <vector>
#include "dataDummy.h"
// TODO Inherits of AsyncSimulator
class remoteDummy{
  public:
    remoteDummy(uint id):m_id(id){};
    ~remoteDummy() = default;
    uint getId() const {return m_id;}
  private:
    uint m_id;
};
