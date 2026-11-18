// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7eb220, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7eb220 LeafForward7eb220::Forward
#include "LeafForward7eb220.h"
extern "C" void* leaf_target(void*);
void* LeafForward7eb220::Forward() { return leaf_target(this); }
