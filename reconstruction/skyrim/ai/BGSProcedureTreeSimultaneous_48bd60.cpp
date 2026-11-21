// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction from the pinned procedure code.
// Adapted bodies: none
// 0x48bd60 BGSProcedureTreeSimultaneous::ReplaceOptions
#include "BGSProcedureTreeSimultaneous_48bd60.h"

void BGSProcedureTreeSimultaneous::ReplaceOptions(ProcedureOptions* replacement)
{
    if (options) {
        delete options;
    }
    options = replacement;
}
