// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1ed50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1ed50 LeafForwardf1ed50::Forward
#include "LeafForwardf1ed50.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1ed50::Forward() { return leaf_target(this); }
