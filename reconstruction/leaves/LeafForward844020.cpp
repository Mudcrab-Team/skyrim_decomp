// Source exposure: binary-analysis; no external implementation reused.
// LeafForward844020, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x844020 LeafForward844020::Forward
#include "LeafForward844020.h"
extern "C" void* leaf_target(void*);
void* LeafForward844020::Forward() { return leaf_target(this); }
