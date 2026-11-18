// Source exposure: binary-analysis
// Staticb1fe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb1fe0;
extern void construct(Staticb1fe0*, const Descriptor*);
extern void destroy(Staticb1fe0*);
struct Staticb1fe0 {
    void* value;
    Staticb1fe0() { construct(this, &descriptor); }
    ~Staticb1fe0() { destroy(this); }
};
