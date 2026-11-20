// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardca3ae0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xca3ae0 LeafForwardca3ae0::Forward
#include "LeafForwardca3ae0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardca3ae0::Forward() { return leaf_target(this); }
