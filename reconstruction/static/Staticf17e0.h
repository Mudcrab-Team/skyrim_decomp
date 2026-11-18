// Source exposure: binary-analysis
// Staticf17e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf17e0;
extern void construct(Staticf17e0*, const Descriptor*);
extern void destroy(Staticf17e0*);
struct Staticf17e0 {
    void* value;
    Staticf17e0() { construct(this, &descriptor); }
    ~Staticf17e0() { destroy(this); }
};
