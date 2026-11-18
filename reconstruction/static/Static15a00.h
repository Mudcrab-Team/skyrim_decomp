// Source exposure: binary-analysis
// Static15a00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15a00;
extern void construct(Static15a00*, const Descriptor*);
extern void destroy(Static15a00*);
struct Static15a00 {
    void* value;
    Static15a00() { construct(this, &descriptor); }
    ~Static15a00() { destroy(this); }
};
