// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
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
