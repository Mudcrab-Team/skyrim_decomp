// Source exposure: binary-analysis; no external implementation reused.
// LeafForward841250, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x841250 LeafForward841250::Forward
#include "LeafForward841250.h"
extern "C" void* leaf_target(void*);
void* LeafForward841250::Forward() { return leaf_target(this); }
