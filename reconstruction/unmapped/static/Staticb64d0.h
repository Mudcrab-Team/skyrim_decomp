// Source exposure: binary-analysis
// Staticb64d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb64d0;
extern void construct(Staticb64d0*, const Descriptor*);
extern void destroy(Staticb64d0*);
struct Staticb64d0 {
    void* value;
    Staticb64d0() { construct(this, &descriptor); }
    ~Staticb64d0() { destroy(this); }
};
