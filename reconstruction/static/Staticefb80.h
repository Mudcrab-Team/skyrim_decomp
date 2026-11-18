// Source exposure: binary-analysis
// Staticefb80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefb80;
extern void construct(Staticefb80*, const Descriptor*);
extern void destroy(Staticefb80*);
struct Staticefb80 {
    void* value;
    Staticefb80() { construct(this, &descriptor); }
    ~Staticefb80() { destroy(this); }
};
