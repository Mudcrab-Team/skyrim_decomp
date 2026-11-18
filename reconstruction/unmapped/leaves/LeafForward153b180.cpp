// Source exposure: binary-analysis; no external implementation reused.
// LeafForward153b180, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x153b180 LeafForward153b180::Forward
#include "LeafForward153b180.h"
extern "C" void* leaf_target(void*);
void* LeafForward153b180::Forward() { return leaf_target(this); }
