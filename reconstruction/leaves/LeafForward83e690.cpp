// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83e690, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83e690 LeafForward83e690::Forward
#include "LeafForward83e690.h"
extern "C" void* leaf_target(void*);
void* LeafForward83e690::Forward() { return leaf_target(this); }
