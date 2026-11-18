// Source exposure: binary-analysis; no external implementation reused.
// LeafForward83eee0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x83eee0 LeafForward83eee0::Forward
#include "LeafForward83eee0.h"
extern "C" void* leaf_target(void*);
void* LeafForward83eee0::Forward() { return leaf_target(this); }
