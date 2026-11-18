// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarda54dc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xa54dc0 LeafForwarda54dc0::Forward
#include "LeafForwarda54dc0.h"
extern "C" void* leaf_target(void*);
void* LeafForwarda54dc0::Forward() { return leaf_target(this); }
