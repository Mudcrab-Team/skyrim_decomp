// GridArray::KillAll: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/Misc/GridArray.cpp:23; target behavior differs where applicable.
// Semantic names and types: GUESS(low)
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// 0x226cd0 GridArray::KillAll
#include "GridArray.h"
void GridArray::KillAll() { DetachAll(); }
