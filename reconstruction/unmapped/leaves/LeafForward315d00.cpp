// Source exposure: binary-analysis; no external implementation reused.
// LeafForward315d00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x315d00 LeafForward315d00::Forward
#include "LeafForward315d00.h"
extern "C" void* leaf_target(void*);
void* LeafForward315d00::Forward() { return leaf_target(this); }
