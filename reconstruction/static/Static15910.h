// Source exposure: binary-analysis
// Static15910, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15910;
extern void construct(Static15910*, const Descriptor*);
extern void destroy(Static15910*);
struct Static15910 {
    void* value;
    Static15910() { construct(this, &descriptor); }
    ~Static15910() { destroy(this); }
};
