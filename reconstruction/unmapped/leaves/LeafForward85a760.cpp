// Source exposure: binary-analysis; no external implementation reused.
// LeafForward85a760, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x85a760 LeafForward85a760::Forward
#include "LeafForward85a760.h"
extern "C" void* leaf_target(void*);
void* LeafForward85a760::Forward() { return leaf_target(this); }
