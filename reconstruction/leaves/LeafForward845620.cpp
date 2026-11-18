// Source exposure: binary-analysis; no external implementation reused.
// LeafForward845620, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x845620 LeafForward845620::Forward
#include "LeafForward845620.h"
extern "C" void* leaf_target(void*);
void* LeafForward845620::Forward() { return leaf_target(this); }
