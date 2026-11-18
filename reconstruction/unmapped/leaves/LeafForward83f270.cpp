// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83f270, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83f270 LeafForward83f270::Forward
#include "LeafForward83f270.h"
extern "C" void* leaf_target(void*);
void* LeafForward83f270::Forward() { return leaf_target(this); }
