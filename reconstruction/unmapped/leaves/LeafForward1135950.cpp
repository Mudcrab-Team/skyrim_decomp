// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1135950, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1135950 LeafForward1135950::Forward
#include "LeafForward1135950.h"
extern "C" void* leaf_target(void*);
void* LeafForward1135950::Forward() { return leaf_target(this); }
