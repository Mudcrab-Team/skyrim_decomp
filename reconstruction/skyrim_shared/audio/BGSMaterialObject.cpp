// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x321c34 BGSMaterialObject::dtor
// 0x321740 BGSMaterialObject::EnsureLoaded
#include "BGSMaterialObject.h"

// The constructor is not compared: it is defined so that this unit emits the vftables and with
// them the destructor thunk.
BGSMaterialObject::BGSMaterialObject()
{
}

BGSMaterialObject::~BGSMaterialObject()
{
}

void BGSMaterialObject::EnsureLoaded()
{
    if (properties.empty() && !fileData.empty()) {
        LoadFileData();
    }
}
