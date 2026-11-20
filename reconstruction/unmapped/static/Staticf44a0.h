// Source exposure: binary-analysis
// Staticf44a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf44a0;
extern void construct(Staticf44a0*, const Descriptor*);
extern void destroy(Staticf44a0*);
struct Staticf44a0 {
    void* value;
    Staticf44a0() { construct(this, &descriptor); }
    ~Staticf44a0() { destroy(this); }
};
