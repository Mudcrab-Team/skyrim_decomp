// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// BSPSysHavokUpdateModifier, SetCollisionObjectHandler, ICollisionObjectHandler: SIBLING(fo4-private@1b765c70, author-permission)
// Fields: GUESS(low); stand-in storage for the observed member offset
#pragma once
#include <cstdint>

class BSPSysHavokUpdateModifier
{
public:
    class ICollisionObjectHandler
    {
    public:
        virtual ~ICollisionObjectHandler();
    };
    void SetCollisionObjectHandler(ICollisionObjectHandler* replacement);
    std::uint8_t state[0x48];
    ICollisionObjectHandler* handler;
};
