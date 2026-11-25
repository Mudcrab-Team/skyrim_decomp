// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x767370 ArrayLeaf767370::~ArrayLeaf767370
// CI hash: 0x767370 ??1ArrayLeaf767370@@QEAA@XZ
#include "ArrayLeaf767370.h"

// guess: same compiled code as matched 0x767370 apart from relocated fields; its role here is not established.
ArrayLeaf767370::~ArrayLeaf767370()
{
    if (data) {
        FreeArrayLeaf767370(this);
        size = 0;
    }
}
