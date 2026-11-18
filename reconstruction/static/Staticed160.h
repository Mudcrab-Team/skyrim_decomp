// Source exposure: binary-analysis
// Staticed160, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticed160;
extern void construct(Staticed160*, const Descriptor*);
extern void destroy(Staticed160*);
struct Staticed160 {
    void* value;
    Staticed160() { construct(this, &descriptor); }
    ~Staticed160() { destroy(this); }
};
