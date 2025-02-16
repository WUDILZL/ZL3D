#pragma once
#include "Coord_system.h"
#include "包围盒.h"

//物体类
class Model_object :
    public Coord_system
{
public:
    Model_object();
    ~Model_object();
public:
    包围盒 物体包围盒;
};

