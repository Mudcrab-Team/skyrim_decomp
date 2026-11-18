// Source exposure: binary-analysis
// Staticefb50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefb50;
extern void construct(Staticefb50*, const Descriptor*);
extern void destroy(Staticefb50*);
struct Staticefb50 {
    void* value;
    Staticefb50() { construct(this, &descriptor); }
    ~Staticefb50() { destroy(this); }
};
