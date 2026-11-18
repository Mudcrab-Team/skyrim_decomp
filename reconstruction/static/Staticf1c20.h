// Source exposure: binary-analysis
// Staticf1c20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf1c20;
extern void construct(Staticf1c20*, const Descriptor*);
extern void destroy(Staticf1c20*);
struct Staticf1c20 {
    void* value;
    Staticf1c20() { construct(this, &descriptor); }
    ~Staticf1c20() { destroy(this); }
};
