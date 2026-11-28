// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x15994b0 BSSystemUtility::SetLostFocus
#include "BSSystemUtility_15994b0.h"

// Invokes the focus callback when the focus state changes, then records the new state.
void BSSystemUtility::SetLostFocus(bool value)
{
    if (value != lostFocus && onFocusChanged)
    {
        onFocusChanged(value);
    }
    lostFocus = value;
}
