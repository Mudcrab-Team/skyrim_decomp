// Source exposure: binary-analysis
// Staticb7bb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7bb0;
extern void construct(Staticb7bb0*, const Descriptor*);
extern void destroy(Staticb7bb0*);
struct Staticb7bb0 {
    void* value;
    Staticb7bb0() { construct(this, &descriptor); }
    ~Staticb7bb0() { destroy(this); }
};
