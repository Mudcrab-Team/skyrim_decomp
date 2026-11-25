// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xff9870 ArrayLeafff9870::~ArrayLeafff9870
// CI hash: 0xff9870 ??1ArrayLeafff9870@@QEAA@XZ
#include "ArrayLeafff9870.h"

// guess: same compiled code as matched 0xff9870 apart from relocated fields; its role here is not established.
ArrayLeafff9870::~ArrayLeafff9870()
{
    if (data) {
        FreeArrayLeafff9870(this);
        size = 0;
    }
}
