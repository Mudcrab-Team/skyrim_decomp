// Source exposure: binary-analysis
// Staticb54c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb54c0;
extern void construct(Staticb54c0*, const Descriptor*);
extern void destroy(Staticb54c0*);
struct Staticb54c0 {
    void* value;
    Staticb54c0() { construct(this, &descriptor); }
    ~Staticb54c0() { destroy(this); }
};
