// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1085260, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1085260 LeafForward1085260::Forward
#include "LeafForward1085260.h"
extern "C" void* leaf_target(void*);
void* LeafForward1085260::Forward() { return leaf_target(this); }
