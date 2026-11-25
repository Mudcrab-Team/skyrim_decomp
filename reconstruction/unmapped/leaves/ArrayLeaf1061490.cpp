// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x1061490 ArrayLeaf1061490::~ArrayLeaf1061490
// CI hash: 0x1061490 ??1ArrayLeaf1061490@@QEAA@XZ
#include "ArrayLeaf1061490.h"

// guess: same compiled code as matched 0x1061490 apart from relocated fields; its role here is not established.
ArrayLeaf1061490::~ArrayLeaf1061490()
{
    if (data) {
        FreeArrayLeaf1061490(this);
        size = 0;
    }
}
