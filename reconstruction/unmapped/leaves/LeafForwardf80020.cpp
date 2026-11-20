// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf80020, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf80020 LeafForwardf80020::Forward
#include "LeafForwardf80020.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf80020::Forward() { return leaf_target(this); }
