// Source exposure: binary-analysis
// Staticb5bb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5bb0;
extern void construct(Staticb5bb0*, const Descriptor*);
extern void destroy(Staticb5bb0*);
struct Staticb5bb0 {
    void* value;
    Staticb5bb0() { construct(this, &descriptor); }
    ~Staticb5bb0() { destroy(this); }
};
