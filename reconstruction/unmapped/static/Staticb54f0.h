// Source exposure: binary-analysis
// Staticb54f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb54f0;
extern void construct(Staticb54f0*, const Descriptor*);
extern void destroy(Staticb54f0*);
struct Staticb54f0 {
    void* value;
    Staticb54f0() { construct(this, &descriptor); }
    ~Staticb54f0() { destroy(this); }
};
