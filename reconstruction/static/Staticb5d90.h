// Source exposure: binary-analysis
// Staticb5d90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5d90;
extern void construct(Staticb5d90*, const Descriptor*);
extern void destroy(Staticb5d90*);
struct Staticb5d90 {
    void* value;
    Staticb5d90() { construct(this, &descriptor); }
    ~Staticb5d90() { destroy(this); }
};
