// Source exposure: binary-analysis; no external implementation reused.
// LeafForward841710, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x841710 LeafForward841710::Forward
#include "LeafForward841710.h"
extern "C" void* leaf_target(void*);
void* LeafForward841710::Forward() { return leaf_target(this); }
