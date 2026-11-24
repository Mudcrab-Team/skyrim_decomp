// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf9dc90 BSPSysHavokUpdateModifier::SetCollisionObjectHandler
#include "BSPSysHavokUpdateModifier_f9dc90.h"

void BSPSysHavokUpdateModifier::SetCollisionObjectHandler(ICollisionObjectHandler* replacement)
{
    if (handler == replacement) {
        return;
    }
    delete handler;
    handler = replacement;
}
