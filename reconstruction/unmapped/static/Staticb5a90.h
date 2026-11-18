// Source exposure: binary-analysis
// Staticb5a90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5a90;
extern void construct(Staticb5a90*, const Descriptor*);
extern void destroy(Staticb5a90*);
struct Staticb5a90 {
    void* value;
    Staticb5a90() { construct(this, &descriptor); }
    ~Staticb5a90() { destroy(this); }
};
