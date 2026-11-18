// Source exposure: binary-analysis
// Staticf660, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf660;
extern void construct(Staticf660*, const Descriptor*);
extern void destroy(Staticf660*);
struct Staticf660 {
    void* value;
    Staticf660() { construct(this, &descriptor); }
    ~Staticf660() { destroy(this); }
};
