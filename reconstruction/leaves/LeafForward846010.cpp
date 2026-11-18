// Source exposure: binary-analysis; no external implementation reused.
// LeafForward846010, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x846010 LeafForward846010::Forward
#include "LeafForward846010.h"
extern "C" void* leaf_target(void*);
void* LeafForward846010::Forward() { return leaf_target(this); }
