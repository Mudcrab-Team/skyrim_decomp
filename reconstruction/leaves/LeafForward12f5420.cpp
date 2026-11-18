// Source exposure: binary-analysis; no external implementation reused.
// LeafForward12f5420, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x12f5420 LeafForward12f5420::Forward
#include "LeafForward12f5420.h"
extern "C" void* leaf_target(void*);
void* LeafForward12f5420::Forward() { return leaf_target(this); }
