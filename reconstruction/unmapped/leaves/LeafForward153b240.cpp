// Source exposure: binary-analysis; no external implementation reused.
// LeafForward153b240, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x153b240 LeafForward153b240::Forward
#include "LeafForward153b240.h"
extern "C" void* leaf_target(void*);
void* LeafForward153b240::Forward() { return leaf_target(this); }
