// Source exposure: binary-analysis; no external implementation reused.
// LeafForward408580, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x408580 LeafForward408580::Forward
#include "LeafForward408580.h"
extern "C" void* leaf_target(void*);
void* LeafForward408580::Forward() { return leaf_target(this); }
