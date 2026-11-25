// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x86f120 ArrayLeaf86f120::~ArrayLeaf86f120
// CI hash: 0x86f120 ??1ArrayLeaf86f120@@QEAA@XZ
#include "ArrayLeaf86f120.h"

// guess: same compiled code as matched 0x86f120 apart from relocated fields; its role here is not established.
ArrayLeaf86f120::~ArrayLeaf86f120()
{
    if (data) {
        FreeArrayLeaf86f120(this);
        size = 0;
    }
}
