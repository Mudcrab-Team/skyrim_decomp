// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused. Stamped as a twin of matched 0x111a20 (unmapped/leaves/ArrayLeaf111a20): source copied, names replaced by placeholders.
// 0xbd7890 ArrayLeafbd7890::~ArrayLeafbd7890
// CI hash: 0xbd7890 ??1ArrayLeafbd7890@@QEAA@XZ
#include "ArrayLeafbd7890.h"

// guess: same compiled code as matched 0xbd7890 apart from relocated fields; its role here is not established.
ArrayLeafbd7890::~ArrayLeafbd7890()
{
    if (data) {
        FreeArrayLeafbd7890(this);
        size = 0;
    }
}
