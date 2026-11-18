// Source exposure: binary-analysis
// Staticed310, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticed310;
extern void construct(Staticed310*, const Descriptor*);
extern void destroy(Staticed310*);
struct Staticed310 {
    void* value;
    Staticed310() { construct(this, &descriptor); }
    ~Staticed310() { destroy(this); }
};
