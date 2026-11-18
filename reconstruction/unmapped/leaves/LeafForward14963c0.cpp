// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14963c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14963c0 LeafForward14963c0::Forward
#include "LeafForward14963c0.h"
extern "C" void* leaf_target(void*);
void* LeafForward14963c0::Forward() { return leaf_target(this); }
