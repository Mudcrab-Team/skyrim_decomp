// Source exposure: binary-analysis; no external implementation reused.
// LeafForward122c540, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x122c540 LeafForward122c540::Forward
#include "LeafForward122c540.h"
extern "C" void* leaf_target(void*);
void* LeafForward122c540::Forward() { return leaf_target(this); }
