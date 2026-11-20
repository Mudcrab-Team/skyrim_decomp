// Source exposure: binary-analysis; no external implementation reused.
// LeafForward59de90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x59de90 LeafForward59de90::Forward
#include "LeafForward59de90.h"
extern "C" void* leaf_target(void*);
void* LeafForward59de90::Forward() { return leaf_target(this); }
