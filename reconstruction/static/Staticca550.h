// Source exposure: binary-analysis
// Staticca550, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca550;
extern void construct(Staticca550*, const Descriptor*);
extern void destroy(Staticca550*);
struct Staticca550 {
    void* value;
    Staticca550() { construct(this, &descriptor); }
    ~Staticca550() { destroy(this); }
};
