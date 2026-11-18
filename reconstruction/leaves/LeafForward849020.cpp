// Source exposure: binary-analysis; no external implementation reused.
// LeafForward849020, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x849020 LeafForward849020::Forward
#include "LeafForward849020.h"
extern "C" void* leaf_target(void*);
void* LeafForward849020::Forward() { return leaf_target(this); }
