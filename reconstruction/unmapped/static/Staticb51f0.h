// Source exposure: binary-analysis
// Staticb51f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb51f0;
extern void construct(Staticb51f0*, const Descriptor*);
extern void destroy(Staticb51f0*);
struct Staticb51f0 {
    void* value;
    Staticb51f0() { construct(this, &descriptor); }
    ~Staticb51f0() { destroy(this); }
};
