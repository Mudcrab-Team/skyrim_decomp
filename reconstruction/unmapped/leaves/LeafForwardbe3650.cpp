// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbe3650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbe3650 LeafForwardbe3650::Forward
#include "LeafForwardbe3650.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbe3650::Forward() { return leaf_target(this); }
