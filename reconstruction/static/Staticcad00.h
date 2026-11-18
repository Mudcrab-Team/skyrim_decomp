// Source exposure: binary-analysis
// Staticcad00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcad00;
extern void construct(Staticcad00*, const Descriptor*);
extern void destroy(Staticcad00*);
struct Staticcad00 {
    void* value;
    Staticcad00() { construct(this, &descriptor); }
    ~Staticcad00() { destroy(this); }
};
