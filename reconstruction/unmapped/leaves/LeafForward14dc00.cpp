// Source exposure: binary-analysis; no external implementation reused.
// LeafForward14dc00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x14dc00 LeafForward14dc00::Forward
#include "LeafForward14dc00.h"
extern "C" void* leaf_target(void*);
void* LeafForward14dc00::Forward() { return leaf_target(this); }
