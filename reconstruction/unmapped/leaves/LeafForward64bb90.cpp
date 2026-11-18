// Source exposure: binary-analysis; no external implementation reused.
// LeafForward64bb90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x64bb90 LeafForward64bb90::Forward
#include "LeafForward64bb90.h"
extern "C" void* leaf_target(void*);
void* LeafForward64bb90::Forward() { return leaf_target(this); }
