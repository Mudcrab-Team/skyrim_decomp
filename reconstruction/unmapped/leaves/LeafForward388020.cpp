// Source exposure: binary-analysis; no external implementation reused.
// LeafForward388020, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x388020 LeafForward388020::Forward
#include "LeafForward388020.h"
extern "C" void* leaf_target(void*);
void* LeafForward388020::Forward() { return leaf_target(this); }
