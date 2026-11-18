// Source exposure: binary-analysis; no external implementation reused.
// LeafForward121dd50, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x121dd50 LeafForward121dd50::Forward
#include "LeafForward121dd50.h"
extern "C" void* leaf_target(void*);
void* LeafForward121dd50::Forward() { return leaf_target(this); }
