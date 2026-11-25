// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x149b490 ArrayLeaf149b490::~ArrayLeaf149b490
// CI hash: 0x149b490 ??1ArrayLeaf149b490@@QEAA@XZ
#include "ArrayLeaf149b490.h"

// guess: same compiled code as matched 0x149b490 apart from relocated fields; its role here is not established.
ArrayLeaf149b490::~ArrayLeaf149b490()
{
    if (data) {
        FreeArrayLeaf149b490(this);
        size = 0;
    }
}
