// Source exposure: binary-analysis
// Staticf2fe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf2fe0;
extern void construct(Staticf2fe0*, const Descriptor*);
extern void destroy(Staticf2fe0*);
struct Staticf2fe0 {
    void* value;
    Staticf2fe0() { construct(this, &descriptor); }
    ~Staticf2fe0() { destroy(this); }
};
