// Source exposure: binary-analysis
// Static15d90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15d90;
extern void construct(Static15d90*, const Descriptor*);
extern void destroy(Static15d90*);
struct Static15d90 {
    void* value;
    Static15d90() { construct(this, &descriptor); }
    ~Static15d90() { destroy(this); }
};
