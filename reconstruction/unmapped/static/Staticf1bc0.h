// Source exposure: binary-analysis
// Staticf1bc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf1bc0;
extern void construct(Staticf1bc0*, const Descriptor*);
extern void destroy(Staticf1bc0*);
struct Staticf1bc0 {
    void* value;
    Staticf1bc0() { construct(this, &descriptor); }
    ~Staticf1bc0() { destroy(this); }
};
