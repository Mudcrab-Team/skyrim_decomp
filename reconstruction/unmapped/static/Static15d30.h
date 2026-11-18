// Source exposure: binary-analysis
// Static15d30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15d30;
extern void construct(Static15d30*, const Descriptor*);
extern void destroy(Static15d30*);
struct Static15d30 {
    void* value;
    Static15d30() { construct(this, &descriptor); }
    ~Static15d30() { destroy(this); }
};
