// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf3d200, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf3d200 LeafForwardf3d200::Forward
#include "LeafForwardf3d200.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf3d200::Forward() { return leaf_target(this); }
