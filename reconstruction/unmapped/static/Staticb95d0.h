// Source exposure: binary-analysis
// Staticb95d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb95d0;
extern void construct(Staticb95d0*, const Descriptor*);
extern void destroy(Staticb95d0*);
struct Staticb95d0 {
    void* value;
    Staticb95d0() { construct(this, &descriptor); }
    ~Staticb95d0() { destroy(this); }
};
