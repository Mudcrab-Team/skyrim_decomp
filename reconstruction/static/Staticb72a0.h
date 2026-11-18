// Source exposure: binary-analysis
// Staticb72a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb72a0;
extern void construct(Staticb72a0*, const Descriptor*);
extern void destroy(Staticb72a0*);
struct Staticb72a0 {
    void* value;
    Staticb72a0() { construct(this, &descriptor); }
    ~Staticb72a0() { destroy(this); }
};
