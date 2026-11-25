// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00aa6fe0::f3_2779::BSValueNode::IsEqual.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00aa0000_o2.cpp:20980
// 0xfd3410 f3m_00aa6fe0::f3_2779::BSValueNode::IsEqual
#include "BSValueNode_fd3410.h"

namespace f3m_00aa6fe0 {
namespace f3_2779 {
char BSValueNode::IsEqual(BSValueNode* other) {
bool result=Func0082e460(other);
if(result) {
BSValueNode* local=other;
int selfValue=p;
int otherValue=local->p;
result=(selfValue==otherValue && flag==local->flag)?1:0;
}
return result;
}
}
}
