// Source exposure: binary-analysis; no external implementation reused.
// LeafForward408470, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x408470 LeafForward408470::Forward
#include "LeafForward408470.h"
extern "C" void* leaf_target(void*);
void* LeafForward408470::Forward() { return leaf_target(this); }
