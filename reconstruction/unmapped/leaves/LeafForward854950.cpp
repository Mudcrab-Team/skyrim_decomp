// Source exposure: binary-analysis; no external implementation reused.
// LeafForward854950, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x854950 LeafForward854950::Forward
#include "LeafForward854950.h"
extern "C" void* leaf_target(void*);
void* LeafForward854950::Forward() { return leaf_target(this); }
