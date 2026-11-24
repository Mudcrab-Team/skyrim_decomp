// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x1211d80 ArrayLeaf1211d80::~ArrayLeaf1211d80
// CI hash: 0x1211d80 ??1ArrayLeaf1211d80@@QEAA@XZ
#include "ArrayLeaf1211d80.h"

// guess: same compiled code as matched 0x1211d80 apart from relocated fields; its role here is not established.
ArrayLeaf1211d80::~ArrayLeaf1211d80()
{
    if (data) {
        FreeArrayLeaf1211d80(this);
        size = 0;
    }
}
