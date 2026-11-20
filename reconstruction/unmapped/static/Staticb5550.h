// Source exposure: binary-analysis
// Staticb5550, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5550;
extern void construct(Staticb5550*, const Descriptor*);
extern void destroy(Staticb5550*);
struct Staticb5550 {
    void* value;
    Staticb5550() { construct(this, &descriptor); }
    ~Staticb5550() { destroy(this); }
};
