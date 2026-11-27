// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: S_00e58ea0_cls::Func00e58ea0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramcreatorhlsl.cpp:588
// 0xcb8770 S_00e58ea0_cls::Func00e58ea0
#include "S_00e58ea0_cls_cb8770.h"

S_00e58ea0_Gen* S_00e58ea0_cls::Func00e58ea0(S_00e58ea0_Gen* a1, S_00e58ea0_Gen* a2)
{
    a1->InitFloatArray(a2->Func00cc0760(), a2->Func00e587a0(), 0.0f);
    S_00e58ea0_Arr tmpArr;
    tmpArr.InitFloatArray(Func00dbbc00(), a2->Func00e587a0(), 0.0f);
    Func00e58a20(a1, a2, &tmpArr);
    tmpArr.Func00c7b0f0();
    return a1;
}
