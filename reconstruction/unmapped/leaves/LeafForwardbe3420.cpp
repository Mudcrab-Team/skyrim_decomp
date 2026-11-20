// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardbe3420, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xbe3420 LeafForwardbe3420::Forward
#include "LeafForwardbe3420.h"
extern "C" void* leaf_target(void*);
void* LeafForwardbe3420::Forward() { return leaf_target(this); }
