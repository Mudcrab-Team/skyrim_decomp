// Source exposure: binary-analysis
// Staticb98d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb98d0;
extern void construct(Staticb98d0*, const Descriptor*);
extern void destroy(Staticb98d0*);
struct Staticb98d0 {
    void* value;
    Staticb98d0() { construct(this, &descriptor); }
    ~Staticb98d0() { destroy(this); }
};
