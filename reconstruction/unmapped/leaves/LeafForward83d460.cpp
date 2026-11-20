// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83d460, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83d460 LeafForward83d460::Forward
#include "LeafForward83d460.h"
extern "C" void* leaf_target(void*);
void* LeafForward83d460::Forward() { return leaf_target(this); }
