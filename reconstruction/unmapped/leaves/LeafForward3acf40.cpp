// Source exposure: binary-analysis; no external implementation reused.
// LeafForward3acf40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x3acf40 LeafForward3acf40::Forward
#include "LeafForward3acf40.h"
extern "C" void* leaf_target(void*);
void* LeafForward3acf40::Forward() { return leaf_target(this); }
