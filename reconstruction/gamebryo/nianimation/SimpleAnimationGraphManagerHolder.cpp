// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// SimpleAnimationGraphManagerHolder::SetAnimationGraphManagerImpl: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/Animation/SimpleAnimationGraphManagerHolder.cpp:73
// SimpleAnimationGraphManagerHolder::GetAnimationGraphManagerImpl: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/Animation/SimpleAnimationGraphManagerHolder.cpp:66
// 0x556670 SimpleAnimationGraphManagerHolder::SetAnimationGraphManagerImpl
// 0x556610 SimpleAnimationGraphManagerHolder::GetAnimationGraphManagerImpl
#include "SimpleAnimationGraphManagerHolder.h"
bool SimpleAnimationGraphManagerHolder::GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& out) const { out=animationGraphManager; return out.ptr != nullptr; }
bool SimpleAnimationGraphManagerHolder::SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& in) { animationGraphManager=in; return true; }
