// Source exposure: binary-analysis
// Static15fd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15fd0;
extern void construct(Static15fd0*, const Descriptor*);
extern void destroy(Static15fd0*);
struct Static15fd0 {
    void* value;
    Static15fd0() { construct(this, &descriptor); }
    ~Static15fd0() { destroy(this); }
};
