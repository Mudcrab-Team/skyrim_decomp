// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xa6bd90 ArrayLeafa6bd90::~ArrayLeafa6bd90
// CI hash: 0xa6bd90 ??1ArrayLeafa6bd90@@QEAA@XZ
#include "ArrayLeafa6bd90.h"

// guess: same compiled code as matched 0xa6bd90 apart from relocated fields; its role here is not established.
ArrayLeafa6bd90::~ArrayLeafa6bd90()
{
    if (data) {
        FreeArrayLeafa6bd90(this);
        size = 0;
    }
}
