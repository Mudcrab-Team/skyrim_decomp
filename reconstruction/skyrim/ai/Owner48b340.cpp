// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code. Stamped as a twin of matched 0x48b9a0 (skyrim/ai/BGSProcedureTreeStackedExecState_48b910): source copied, names replaced by placeholders.
// 0x48b340 Owner48b340::Function48b340
#include "Owner48b340.h"

// guess: same compiled code as matched 0x48b9a0 apart from relocated fields; its role here is not established.
void Owner48b340::Function48b340()
{
    if (child) {
        child->Slot08();
    }
}
