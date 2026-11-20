// Source exposure: binary-analysis
// Statica6410, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6410;
extern void construct(Statica6410*, const Descriptor*);
extern void destroy(Statica6410*);
struct Statica6410 {
    void* value;
    Statica6410() { construct(this, &descriptor); }
    ~Statica6410() { destroy(this); }
};
