// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11cd040, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11cd040 LeafForward11cd040::Forward
#include "LeafForward11cd040.h"
extern "C" void* leaf_target(void*);
void* LeafForward11cd040::Forward() { return leaf_target(this); }
