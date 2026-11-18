// Source exposure: binary-analysis
// Staticb4070, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4070;
extern void construct(Staticb4070*, const Descriptor*);
extern void destroy(Staticb4070*);
struct Staticb4070 {
    void* value;
    Staticb4070() { construct(this, &descriptor); }
    ~Staticb4070() { destroy(this); }
};
