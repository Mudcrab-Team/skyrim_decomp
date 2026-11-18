// Source exposure: binary-analysis; no external implementation reused.
// LeafForward5dd180, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x5dd180 LeafForward5dd180::Forward
#include "LeafForward5dd180.h"
extern "C" void* leaf_target(void*);
void* LeafForward5dd180::Forward() { return leaf_target(this); }
