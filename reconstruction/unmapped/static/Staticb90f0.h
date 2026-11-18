// Source exposure: binary-analysis
// Staticb90f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb90f0;
extern void construct(Staticb90f0*, const Descriptor*);
extern void destroy(Staticb90f0*);
struct Staticb90f0 {
    void* value;
    Staticb90f0() { construct(this, &descriptor); }
    ~Staticb90f0() { destroy(this); }
};
