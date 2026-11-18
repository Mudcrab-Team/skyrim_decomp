// Source exposure: binary-analysis
// Static15190, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15190;
extern void construct(Static15190*, const Descriptor*);
extern void destroy(Static15190*);
struct Static15190 {
    void* value;
    Static15190() { construct(this, &descriptor); }
    ~Static15190() { destroy(this); }
};
