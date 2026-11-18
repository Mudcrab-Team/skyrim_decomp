// Source exposure: binary-analysis; no external implementation reused.
// LeafForward841460, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x841460 LeafForward841460::Forward
#include "LeafForward841460.h"
extern "C" void* leaf_target(void*);
void* LeafForward841460::Forward() { return leaf_target(this); }
