// Source exposure: binary-analysis; no external implementation reused.
// LeafForward2a2020, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x2a2020 LeafForward2a2020::Forward
#include "LeafForward2a2020.h"
extern "C" void* leaf_target(void*);
void* LeafForward2a2020::Forward() { return leaf_target(this); }
