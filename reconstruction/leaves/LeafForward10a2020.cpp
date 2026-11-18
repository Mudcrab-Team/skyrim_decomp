// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10a2020, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10a2020 LeafForward10a2020::Forward
#include "LeafForward10a2020.h"
extern "C" void* leaf_target(void*);
void* LeafForward10a2020::Forward() { return leaf_target(this); }
