// Source exposure: mixed (pinned image and sibling symbol names).
// Code origin: original hand-written reconstruction.
// BSXAudio2AudioListener, SetOrientation: SYMBOLS(tesv-2013-map)
// 0xcd8d40 BSXAudio2AudioListener::SetOrientation
#include "BSXAudio2AudioListener_cd8d40.h"

void BSXAudio2AudioListener::SetOrientation(const ListenerVector& direction, const ListenerVector& up)
{
    front.x = direction.x;
    front.y = direction.y;
    front.z = direction.z;
    top.x = up.x;
    top.y = up.y;
    top.z = up.z;
    x3dFront.x = direction.x;
    x3dFront.y = direction.z;
    x3dFront.z = direction.y;
    x3dTop.x = up.x;
    x3dTop.y = up.z;
    x3dTop.z = up.y;
}
