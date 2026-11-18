// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// BSFaceGenNiNode::UpdateDownwardPass: SIBLING(fo4-private@1b765c70, author-permission); adapted to target calls.
// Sibling source: fo4-private@1b765c70 src/Shared/FaceGen/BSFaceGenNiNode.cpp:156
// names: GUESS(low); signatures and helper identities need independent review.
// 0x439650 BSFaceGenNiNode::UpdateDownwardPass
#include "BSFaceGenNiNode.h"
void BSFaceGenNiNode::UpdateDownwardPass(NiUpdateData& data, unsigned flagsValue) { if ((flags & 1) == 0) UpdateMorphing(data); NiNode::UpdateDownwardPass(data, flagsValue); }
