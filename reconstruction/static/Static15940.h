// Source exposure: binary-analysis
// Static15940, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15940;
extern void construct(Static15940*, const Descriptor*);
extern void destroy(Static15940*);
struct Static15940 {
    void* value;
    Static15940() { construct(this, &descriptor); }
    ~Static15940() { destroy(this); }
};
