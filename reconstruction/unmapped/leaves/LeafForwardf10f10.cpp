// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf10f10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf10f10 LeafForwardf10f10::Forward
#include "LeafForwardf10f10.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf10f10::Forward() { return leaf_target(this); }
