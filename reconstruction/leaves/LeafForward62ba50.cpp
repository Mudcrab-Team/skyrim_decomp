// Source exposure: binary-analysis; no external implementation reused.
// LeafForward62ba50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x62ba50 LeafForward62ba50::Forward
#include "LeafForward62ba50.h"
extern "C" void* leaf_target(void*);
void* LeafForward62ba50::Forward() { return leaf_target(this); }
