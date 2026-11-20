// Source exposure: binary-analysis
// Staticb5880, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5880;
extern void construct(Staticb5880*, const Descriptor*);
extern void destroy(Staticb5880*);
struct Staticb5880 {
    void* value;
    Staticb5880() { construct(this, &descriptor); }
    ~Staticb5880() { destroy(this); }
};
