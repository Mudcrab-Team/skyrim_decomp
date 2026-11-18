// Source exposure: mixed. Drafted by claude-sonnet-5-5 from a local instruction listing and
// 0xef8900 NiTimeController::ProcessClone
#include "NiTimeController.h"

void NiTimeController::ProcessClone(NiCloningProcess& a_cloning)
{
    NiObject::ProcessClone(a_cloning);
    if (next) {
        next->ProcessClone(a_cloning);
    }
}

bool NiTimeController::IsStreamable()
{
    return true;
}

bool NiTimeController::IsTransformController()
{
    return false;
}

bool NiTimeController::IsVertexController()
{
    return false;
}
