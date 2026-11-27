// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Adapted bodies: none known. The origin check reports IsKindOf, NiNode::GetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:4166
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00560000_o2.cpp:19104
// 0x766a90 TraverseScenegraphObjects<SetBlendCollisionFieldVisitor> (CrashLogger PDB: NiAVObject::SetBlendCollisionFieldRecursive)
#include "NiAVObject_766a90.h"

// Instantiate scene-graph traversal copying a field value into every bhkBlendCollisionObject in a subtree.
template BSVisitControl TraverseScenegraphObjects<SetBlendCollisionFieldVisitor>(NiAVObject* object, SetBlendCollisionFieldVisitor& visitor);
