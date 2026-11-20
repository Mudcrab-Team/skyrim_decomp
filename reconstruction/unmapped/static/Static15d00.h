// Source exposure: binary-analysis
// Static15d00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15d00;
extern void construct(Static15d00*, const Descriptor*);
extern void destroy(Static15d00*);
struct Static15d00 {
    void* value;
    Static15d00() { construct(this, &descriptor); }
    ~Static15d00() { destroy(this); }
};
