// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x316110 BGSCameraPath::InitializeData
// 0x317ce0 BGSCameraPath::~BGSCameraPath
#include "BGSCameraPath.h"

// The constructor is not compared: it is defined so that this unit emits the vftable and with it
// the deleting destructor.
BGSCameraPath::BGSCameraPath()
{
}

void BGSCameraPath::InitializeData()
{
    data = 0;
    parentPath = nullptr;
    prevPath = nullptr;
}
