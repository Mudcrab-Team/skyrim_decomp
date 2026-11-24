// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x822910 ArrayLeaf822910::~ArrayLeaf822910
// CI hash: 0x822910 ??1ArrayLeaf822910@@QEAA@XZ
#include "ArrayLeaf822910.h"

// guess: same compiled code as matched 0x822910 apart from relocated fields; its role here is not established.
ArrayLeaf822910::~ArrayLeaf822910()
{
    if (data) {
        FreeArrayLeaf822910(this);
        size = 0;
    }
}
