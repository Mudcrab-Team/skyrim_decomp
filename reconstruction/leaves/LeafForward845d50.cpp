// Source exposure: binary-analysis; no external implementation reused.
// LeafForward845d50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x845d50 LeafForward845d50::Forward
#include "LeafForward845d50.h"
extern "C" void* leaf_target(void*);
void* LeafForward845d50::Forward() { return leaf_target(this); }
