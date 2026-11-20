// Source exposure: binary-analysis
// Staticb7de0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7de0;
extern void construct(Staticb7de0*, const Descriptor*);
extern void destroy(Staticb7de0*);
struct Staticb7de0 {
    void* value;
    Staticb7de0() { construct(this, &descriptor); }
    ~Staticb7de0() { destroy(this); }
};
