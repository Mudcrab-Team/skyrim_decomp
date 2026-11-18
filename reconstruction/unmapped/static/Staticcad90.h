// Source exposure: binary-analysis
// Staticcad90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcad90;
extern void construct(Staticcad90*, const Descriptor*);
extern void destroy(Staticcad90*);
struct Staticcad90 {
    void* value;
    Staticcad90() { construct(this, &descriptor); }
    ~Staticcad90() { destroy(this); }
};
