// Source exposure: binary-analysis
// Staticb7db0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7db0;
extern void construct(Staticb7db0*, const Descriptor*);
extern void destroy(Staticb7db0*);
struct Staticb7db0 {
    void* value;
    Staticb7db0() { construct(this, &descriptor); }
    ~Staticb7db0() { destroy(this); }
};
