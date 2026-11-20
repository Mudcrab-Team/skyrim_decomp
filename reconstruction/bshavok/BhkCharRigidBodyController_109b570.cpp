// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation from the world guard and rigid body support call.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0x109b570 BhkCharRigidBodyController::CheckSupportImpl
#include "BhkCharRigidBodyController_109b570.h"

// ScopedWorldReadLock: GUESS(low)
class ScopedWorldReadLock
{
public:
    explicit ScopedWorldReadLock(bhkWorld* owner) : mode(0)
    {
        if (owner) {
            world = owner->vtable->GetWorld2(owner);
            if (world && world->userData) {
                world->userData->ReadLock();
            }
        } else {
            world = nullptr;
        }
    }

    ~ScopedWorldReadLock()
    {
        if (world && world->userData) {
            world->userData->ReadUnlock();
        }
    }

private:
    ahkpWorld* world;
    std::uint32_t mode;
};

void BhkCharRigidBodyController::CheckSupportImpl()
{
    {
        hkpCharacterRigidBody* body;
        auto* world = charRigidBody.FetchWorld(body);
        ScopedWorldReadLock guard(world ? world->userData : nullptr);
        body->vtable->CheckSupport(body, stepInfo, surfaceInfo);
    }
    supportNorm = surfaceInfo.surfaceNormal;
}

// Keeps the body fetch and virtual dispatch in the controller entry.
__forceinline ahkpWorld* bhkCharacterRigidBody::FetchWorld(hkpCharacterRigidBody*& body)
{
    body = referencedObject;
    return vtable->GetWorld1(this);
}
