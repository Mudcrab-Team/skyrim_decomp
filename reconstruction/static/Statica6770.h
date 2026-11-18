// Source exposure: binary-analysis
// Statica6770, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6770;
extern void construct(Statica6770*, const Descriptor*);
extern void destroy(Statica6770*);
struct Statica6770 {
    void* value;
    Statica6770() { construct(this, &descriptor); }
    ~Statica6770() { destroy(this); }
};
