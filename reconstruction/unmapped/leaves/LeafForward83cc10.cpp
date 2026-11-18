// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83cc10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83cc10 LeafForward83cc10::Forward
#include "LeafForward83cc10.h"
extern "C" void* leaf_target(void*);
void* LeafForward83cc10::Forward() { return leaf_target(this); }
