// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0x1578750 ArrayLeaf1578750::~ArrayLeaf1578750
// CI hash: 0x1578750 ??1ArrayLeaf1578750@@QEAA@XZ
#include "ArrayLeaf1578750.h"

// guess: same compiled code as matched 0x1578750 apart from relocated fields; its role here is not established.
ArrayLeaf1578750::~ArrayLeaf1578750()
{
    if (data) {
        FreeArrayLeaf1578750(this);
        size = 0;
    }
}
