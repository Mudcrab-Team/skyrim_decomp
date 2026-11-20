// Source exposure: binary-analysis
// Staticefd00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefd00;
extern void construct(Staticefd00*, const Descriptor*);
extern void destroy(Staticefd00*);
struct Staticefd00 {
    void* value;
    Staticefd00() { construct(this, &descriptor); }
    ~Staticefd00() { destroy(this); }
};
