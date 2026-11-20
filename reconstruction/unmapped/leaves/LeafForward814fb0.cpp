// Source exposure: binary-analysis; no external implementation reused.
// LeafForward814fb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x814fb0 LeafForward814fb0::Forward
#include "LeafForward814fb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward814fb0::Forward() { return leaf_target(this); }
