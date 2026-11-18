// Source exposure: binary-analysis
// Staticb5310, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5310;
extern void construct(Staticb5310*, const Descriptor*);
extern void destroy(Staticb5310*);
struct Staticb5310 {
    void* value;
    Staticb5310() { construct(this, &descriptor); }
    ~Staticb5310() { destroy(this); }
};
