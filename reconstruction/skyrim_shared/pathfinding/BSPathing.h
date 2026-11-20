// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation using the observed cleanup and partial layouts.
// BSPathing: EXE_RTTI
// BSTSingletonExplicit, g_pathingSingleton, triangleFilter: GUESS(low)
// FindTriangleForLocationFilter: EXE_RTTI
// BSTSingletonExplicit: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class BSPathing;
extern BSPathing* g_pathingSingleton;

class BSTSingletonExplicit
{
protected:
    ~BSTSingletonExplicit() { g_pathingSingleton = nullptr; }
};

struct FindTriangleForLocationFilter
{
    virtual ~FindTriangleForLocationFilter() {}
};

class BSPathing : public BSTSingletonExplicit
{
public:
    BSPathing();
    virtual ~BSPathing();

private:
    FindTriangleForLocationFilter triangleFilter;
    std::uint8_t padding10[8];
};
static_assert(sizeof(BSPathing) == 0x18, "observed allocation size");
