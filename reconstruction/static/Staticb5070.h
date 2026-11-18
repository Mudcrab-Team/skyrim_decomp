// Source exposure: binary-analysis
// Staticb5070, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5070;
extern void construct(Staticb5070*, const Descriptor*);
extern void destroy(Staticb5070*);
struct Staticb5070 {
    void* value;
    Staticb5070() { construct(this, &descriptor); }
    ~Staticb5070() { destroy(this); }
};
