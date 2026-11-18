// Source exposure: binary-analysis; no external implementation reused.
// LeafForward153b170, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x153b170 LeafForward153b170::Forward
#include "LeafForward153b170.h"
extern "C" void* leaf_target(void*);
void* LeafForward153b170::Forward() { return leaf_target(this); }
