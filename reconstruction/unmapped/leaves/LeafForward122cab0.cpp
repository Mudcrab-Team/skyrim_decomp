// Source exposure: binary-analysis; no external implementation reused.
// LeafForward122cab0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x122cab0 LeafForward122cab0::Forward
#include "LeafForward122cab0.h"
extern "C" void* leaf_target(void*);
void* LeafForward122cab0::Forward() { return leaf_target(this); }
