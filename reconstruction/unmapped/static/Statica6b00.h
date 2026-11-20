// Source exposure: binary-analysis
// Statica6b00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6b00;
extern void construct(Statica6b00*, const Descriptor*);
extern void destroy(Statica6b00*);
struct Statica6b00 {
    void* value;
    Statica6b00() { construct(this, &descriptor); }
    ~Statica6b00() { destroy(this); }
};
