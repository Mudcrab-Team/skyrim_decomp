// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x9ec190 ArrayLeaf9ec190::~ArrayLeaf9ec190
// CI hash: 0x9ec190 ??1ArrayLeaf9ec190@@QEAA@XZ
#include "ArrayLeaf9ec190.h"

// guess: same compiled code as matched 0x9ec190 apart from relocated fields; its role here is not established.
ArrayLeaf9ec190::~ArrayLeaf9ec190()
{
    if (data) {
        FreeArrayLeaf9ec190(this);
        size = 0;
    }
}
