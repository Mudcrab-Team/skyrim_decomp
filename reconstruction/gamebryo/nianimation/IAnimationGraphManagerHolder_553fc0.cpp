// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of the holder update and retained manager release.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0x553fc0 IAnimationGraphManagerHolder::UpdateAnimationGraphManager
#include "IAnimationGraphManagerHolder_553fc0.h"

#include <intrin.h>

struct GraphManagerRef
{
    BSAnimationGraphManager* manager = nullptr;

    ~GraphManagerRef()
    {
        auto* retained = manager;
        // Atomically release the reference shared across graph holders.
        if (retained && _InterlockedExchangeAdd(&retained->refCount, -1) == 1) {
            delete retained;
        }
    }
};

bool IAnimationGraphManagerHolder::UpdateAnimationGraphManager(const BSAnimationUpdateData& data)
{
    bool updated = false;
    GraphManagerRef reference;
    if ((data.skipUpdateCheck || vtable->Unk_0E(this)) && vtable->GetAnimationGraphManagerImpl(this, reference)) {
        reference.manager->Update(data);
        updated = true;
    }
    return updated;
}
