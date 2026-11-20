// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10c1640, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10c1640 LeafForward10c1640::Forward
#include "LeafForward10c1640.h"
extern "C" void* leaf_target(void*);
void* LeafForward10c1640::Forward() { return leaf_target(this); }
