// Source exposure: binary-analysis; no external implementation reused.
// LeafForward123da90, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x123da90 LeafForward123da90::Forward
#include "LeafForward123da90.h"
extern "C" void* leaf_target(void*);
void* LeafForward123da90::Forward() { return leaf_target(this); }
