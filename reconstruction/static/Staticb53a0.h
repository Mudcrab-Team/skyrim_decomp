// Source exposure: binary-analysis
// Staticb53a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb53a0;
extern void construct(Staticb53a0*, const Descriptor*);
extern void destroy(Staticb53a0*);
struct Staticb53a0 {
    void* value;
    Staticb53a0() { construct(this, &descriptor); }
    ~Staticb53a0() { destroy(this); }
};
