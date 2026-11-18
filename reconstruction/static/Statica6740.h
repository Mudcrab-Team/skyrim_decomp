// Source exposure: binary-analysis
// Statica6740, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6740;
extern void construct(Statica6740*, const Descriptor*);
extern void destroy(Statica6740*);
struct Statica6740 {
    void* value;
    Statica6740() { construct(this, &descriptor); }
    ~Statica6740() { destroy(this); }
};
