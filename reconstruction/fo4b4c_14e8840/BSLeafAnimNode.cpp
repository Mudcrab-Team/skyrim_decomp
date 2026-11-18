// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BSLeafAnimNode::RegisterStreamables: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target call and boolean normalization.
// Sibling source: fo4-private@1b765c70 src/BSShader/BSLeafAnimNode.cpp:21
// names: GUESS(low); qualified name is unverified.
// 0x14e8840 BSLeafAnimNode::RegisterStreamables
#include "BSLeafAnimNode.h"
bool BSLeafAnimNode::RegisterStreamables(NiStream& stream) { return NiNode::RegisterStreamables(stream) != 0; }
