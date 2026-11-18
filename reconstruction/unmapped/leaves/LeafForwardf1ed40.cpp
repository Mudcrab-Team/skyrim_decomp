// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardf1ed40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xf1ed40 LeafForwardf1ed40::Forward
#include "LeafForwardf1ed40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardf1ed40::Forward() { return leaf_target(this); }
