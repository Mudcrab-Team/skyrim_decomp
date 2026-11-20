// Source exposure: binary-analysis
// Staticb9120, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9120;
extern void construct(Staticb9120*, const Descriptor*);
extern void destroy(Staticb9120*);
struct Staticb9120 {
    void* value;
    Staticb9120() { construct(this, &descriptor); }
    ~Staticb9120() { destroy(this); }
};
