// Source exposure: binary-analysis
// Statica9210, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica9210;
extern void construct(Statica9210*, const Descriptor*);
extern void destroy(Statica9210*);
struct Statica9210 {
    void* value;
    Statica9210() { construct(this, &descriptor); }
    ~Statica9210() { destroy(this); }
};
