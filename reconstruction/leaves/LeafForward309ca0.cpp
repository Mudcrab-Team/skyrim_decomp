// Source exposure: binary-analysis; no external implementation reused.
// LeafForward309ca0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x309ca0 LeafForward309ca0::Forward
#include "LeafForward309ca0.h"
extern "C" void* leaf_target(void*);
void* LeafForward309ca0::Forward() { return leaf_target(this); }
