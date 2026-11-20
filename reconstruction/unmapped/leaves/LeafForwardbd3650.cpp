// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbd3650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbd3650 LeafForwardbd3650::Forward
#include "LeafForwardbd3650.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbd3650::Forward() { return leaf_target(this); }
