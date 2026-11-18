// Source exposure: binary-analysis
// Staticcad60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcad60;
extern void construct(Staticcad60*, const Descriptor*);
extern void destroy(Staticcad60*);
struct Staticcad60 {
    void* value;
    Staticcad60() { construct(this, &descriptor); }
    ~Staticcad60() { destroy(this); }
};
