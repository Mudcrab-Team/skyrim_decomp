// Source exposure: binary-analysis; no external implementation reused.
// LeafForward846e80, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x846e80 LeafForward846e80::Forward
#include "LeafForward846e80.h"
extern "C" void* leaf_target(void*);
void* LeafForward846e80::Forward() { return leaf_target(this); }
