// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1490030, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1490030 LeafForward1490030::Forward
#include "LeafForward1490030.h"
extern "C" void* leaf_target(void*);
void* LeafForward1490030::Forward() { return leaf_target(this); }
