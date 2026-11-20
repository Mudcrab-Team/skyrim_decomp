// Source exposure: binary-analysis; no external implementation reused.
// LeafForward121c650, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x121c650 LeafForward121c650::Forward
#include "LeafForward121c650.h"
extern "C" void* leaf_target(void*);
void* LeafForward121c650::Forward() { return leaf_target(this); }
