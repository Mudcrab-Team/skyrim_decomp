// Source exposure: binary-analysis
// Staticf1810, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf1810;
extern void construct(Staticf1810*, const Descriptor*);
extern void destroy(Staticf1810*);
struct Staticf1810 {
    void* value;
    Staticf1810() { construct(this, &descriptor); }
    ~Staticf1810() { destroy(this); }
};
