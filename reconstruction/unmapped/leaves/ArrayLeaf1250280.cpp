// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x1250280 ArrayLeaf1250280::~ArrayLeaf1250280
// CI hash: 0x1250280 ??1ArrayLeaf1250280@@QEAA@XZ
#include "ArrayLeaf1250280.h"

// guess: same compiled code as matched 0x1250280 apart from relocated fields; its role here is not established.
ArrayLeaf1250280::~ArrayLeaf1250280()
{
    if (data) {
        FreeArrayLeaf1250280(this);
        size = 0;
    }
}
