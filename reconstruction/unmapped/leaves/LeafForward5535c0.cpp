// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5535c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5535c0 LeafForward5535c0::Forward
#include "LeafForward5535c0.h"
extern "C" void* leaf_target(void*);
void* LeafForward5535c0::Forward() { return leaf_target(this); }
