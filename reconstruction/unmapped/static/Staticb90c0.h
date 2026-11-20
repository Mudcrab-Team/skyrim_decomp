// Source exposure: binary-analysis
// Staticb90c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb90c0;
extern void construct(Staticb90c0*, const Descriptor*);
extern void destroy(Staticb90c0*);
struct Staticb90c0 {
    void* value;
    Staticb90c0() { construct(this, &descriptor); }
    ~Staticb90c0() { destroy(this); }
};
