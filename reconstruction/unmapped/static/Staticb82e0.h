// Source exposure: binary-analysis
// Staticb82e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb82e0;
extern void construct(Staticb82e0*, const Descriptor*);
extern void destroy(Staticb82e0*);
struct Staticb82e0 {
    void* value;
    Staticb82e0() { construct(this, &descriptor); }
    ~Staticb82e0() { destroy(this); }
};
