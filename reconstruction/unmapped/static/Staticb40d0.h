// Source exposure: binary-analysis
// Staticb40d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb40d0;
extern void construct(Staticb40d0*, const Descriptor*);
extern void destroy(Staticb40d0*);
struct Staticb40d0 {
    void* value;
    Staticb40d0() { construct(this, &descriptor); }
    ~Staticb40d0() { destroy(this); }
};
