// Source exposure: binary-analysis
// Staticb7ca0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7ca0;
extern void construct(Staticb7ca0*, const Descriptor*);
extern void destroy(Staticb7ca0*);
struct Staticb7ca0 {
    void* value;
    Staticb7ca0() { construct(this, &descriptor); }
    ~Staticb7ca0() { destroy(this); }
};
