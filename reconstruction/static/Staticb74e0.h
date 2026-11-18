// Source exposure: binary-analysis
// Staticb74e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb74e0;
extern void construct(Staticb74e0*, const Descriptor*);
extern void destroy(Staticb74e0*);
struct Staticb74e0 {
    void* value;
    Staticb74e0() { construct(this, &descriptor); }
    ~Staticb74e0() { destroy(this); }
};
