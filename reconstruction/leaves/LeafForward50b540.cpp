// Source exposure: binary-analysis; no external implementation reused.
// LeafForward50b540, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x50b540 LeafForward50b540::Forward
#include "LeafForward50b540.h"
extern "C" void* leaf_target(void*);
void* LeafForward50b540::Forward() { return leaf_target(this); }
