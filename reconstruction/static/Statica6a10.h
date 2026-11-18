// Source exposure: binary-analysis
// Statica6a10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6a10;
extern void construct(Statica6a10*, const Descriptor*);
extern void destroy(Statica6a10*);
struct Statica6a10 {
    void* value;
    Statica6a10() { construct(this, &descriptor); }
    ~Statica6a10() { destroy(this); }
};
