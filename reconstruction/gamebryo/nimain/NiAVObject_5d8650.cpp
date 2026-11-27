// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Adapted bodies: none known. The origin check reports NiNode::GetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:4166
// 0x5d8650 TraverseScenegraphObjects<AlwaysDrawVisitor> (CrashLogger PDB: NiAVObject::SetAlwaysDrawRecursive)
#include "NiAVObject_5d8650.h"

// Instantiate scene-graph traversal setting the always-draw flag and unit bound radius across a subtree.
template BSVisitControl TraverseScenegraphObjects<AlwaysDrawVisitor>(NiAVObject* object, AlwaysDrawVisitor& visitor);
