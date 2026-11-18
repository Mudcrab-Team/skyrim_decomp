// Source exposure: binary-analysis
// Static15d60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15d60;
extern void construct(Static15d60*, const Descriptor*);
extern void destroy(Static15d60*);
struct Static15d60 {
    void* value;
    Static15d60() { construct(this, &descriptor); }
    ~Static15d60() { destroy(this); }
};
