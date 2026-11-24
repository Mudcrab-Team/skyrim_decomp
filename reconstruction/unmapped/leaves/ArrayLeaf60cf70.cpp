// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x60cf70 ArrayLeaf60cf70::~ArrayLeaf60cf70
// CI hash: 0x60cf70 ??1ArrayLeaf60cf70@@QEAA@XZ
#include "ArrayLeaf60cf70.h"

// guess: same compiled code as matched 0x60cf70 apart from relocated fields; its role here is not established.
ArrayLeaf60cf70::~ArrayLeaf60cf70()
{
    if (data) {
        FreeArrayLeaf60cf70(this);
        size = 0;
    }
}
