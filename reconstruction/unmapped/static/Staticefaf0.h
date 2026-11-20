// Source exposure: binary-analysis
// Staticefaf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefaf0;
extern void construct(Staticefaf0*, const Descriptor*);
extern void destroy(Staticefaf0*);
struct Staticefaf0 {
    void* value;
    Staticefaf0() { construct(this, &descriptor); }
    ~Staticefaf0() { destroy(this); }
};
