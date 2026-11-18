// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x340ec0 TESLoadScreen::ClearData
#include "TESLoadScreen.h"

void TESLoadScreen::InitializeData()
{
}

void TESLoadScreen::ClearData()
{
    conditions.Clear();
    if (loadNIFData) {
        loadNIFData->cameraPath.ClearDataComponent();
    }
    TESForm::ClearData();
}
