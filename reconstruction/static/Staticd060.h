// Source exposure: binary-analysis
// Staticd060, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd060;
extern void construct(Staticd060*, const Descriptor*);
extern void destroy(Staticd060*);
struct Staticd060 {
    void* value;
    Staticd060() { construct(this, &descriptor); }
    ~Staticd060() { destroy(this); }
};
