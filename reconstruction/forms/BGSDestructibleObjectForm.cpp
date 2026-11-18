// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// 0x1d2750 BGSDestructibleObjectForm::InitializeDataComponent
// 0x1d2760 BGSDestructibleObjectForm::ClearDataComponent
#include "BGSDestructibleObjectForm.h"

void BGSDestructibleObjectForm::InitializeDataComponent()
{
    data = nullptr;
}

void BGSDestructibleObjectForm::ClearDataComponent()
{
    if (data) {
        data->Destroy(1);
    }
    data = nullptr;
}
