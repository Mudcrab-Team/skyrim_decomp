// Source exposure: binary-analysis; no external implementation reused.
// LeafForward12340b0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x12340b0 LeafForward12340b0::Forward
#include "LeafForward12340b0.h"
extern "C" void* leaf_target(void*);
void* LeafForward12340b0::Forward() { return leaf_target(this); }
