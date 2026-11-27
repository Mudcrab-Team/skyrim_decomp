// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00aa9a10::Copyaa9a10::BSRangeNode::CopyMembers.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00aa0000_o2.cpp:31305
// 0xfdd480 f3m_00aa9a10::Copyaa9a10::BSRangeNode::CopyMembers
#include "BSRangeNode_fdd480.h"

namespace f3m_00aa9a10 {
namespace Copyaa9a10 {
void BSRangeNode::CopyMembers(BSRangeNode* dest,void* context) {
Func00ab5d90(dest,context);
dest->first=first;
dest->second=second;
dest->Func00aa98d0(mode);
}
}
}
