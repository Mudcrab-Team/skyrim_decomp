// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83e970, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83e970 LeafForward83e970::Forward
#include "LeafForward83e970.h"
extern "C" void* leaf_target(void*);
void* LeafForward83e970::Forward() { return leaf_target(this); }
