// Source exposure: mixed. Drafted by claude-sonnet-5-5 from a local instruction listing and
// decompiler output of the pinned image, with types from the header beside this file.
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xce3970 BSTimer::SetGlobalTimeMultiplier
#include "BSTimer.h"

void BSTimer::SetGlobalTimeMultiplier(float a_multiplier, bool a_arg2)
{
    // The flag is read before the global store: bool aliases any object, so the store would
    // otherwise force a reload after it.
    const bool useTarget = useGlobalTimeMultiplierTarget;
    QGlobalTimeMultiplierTarget = a_multiplier;
    if (useTarget) {
        if (a_arg2) {
            QGlobalTimeMultiplier = a_multiplier;
        }
    } else if (a_multiplier != QGlobalTimeMultiplier) {
        delta /= QGlobalTimeMultiplier;
        QGlobalTimeMultiplier = a_multiplier;
        delta *= a_multiplier;
    }
}
