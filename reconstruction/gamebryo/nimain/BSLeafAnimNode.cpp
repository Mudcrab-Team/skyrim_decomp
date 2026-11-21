// Source exposure: mixed
// Origin: original reconstruction from the pinned image and an anonymous sibling.
// BSLeafAnimNode::RegisterStreamables: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target call and boolean normalization.
// Sibling source: fo4-private@1b765c70 src/BSShader/BSLeafAnimNode.cpp:21
// NiNode::~NiNode, BSFadeNode::~BSFadeNode, BSLeafAnimNode::~BSLeafAnimNode: GUESS(low); read from the image's own destructor chain, not from the sibling.
// Code origin: original; the pinned listing and community declarations only
// Adapted bodies: BSLeafAnimNode::RegisterStreamables (fo4-private@1b765c70 src/BSShader/BSLeafAnimNode.cpp:21)
// SPDX-License-Identifier: CC0-1.0
// 0x14e8840 BSLeafAnimNode::RegisterStreamables
// 0x14e5e90 BSFadeNode::~BSFadeNode
// 0x14e89b0 BSLeafAnimNode::~BSLeafAnimNode
#include "BSLeafAnimNode.h"

bool BSLeafAnimNode::RegisterStreamables(NiStream& stream) { return NiNode::RegisterStreamables(stream) != 0; }

// noinline: its own body at its own RVA (0x14e5e90); the compared destructor at 0x14e89b0 reaches it
// by a tail jump, so it must not be inlined here (cookbook rule 27).
__declspec(noinline) BSFadeNode::~BSFadeNode()
{
}

BSLeafAnimNode::~BSLeafAnimNode()
{
}
