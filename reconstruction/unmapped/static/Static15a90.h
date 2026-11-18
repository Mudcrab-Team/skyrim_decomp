// Source exposure: binary-analysis
// Static15a90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15a90;
extern void construct(Static15a90*, const Descriptor*);
extern void destroy(Static15a90*);
struct Static15a90 {
    void* value;
    Static15a90() { construct(this, &descriptor); }
    ~Static15a90() { destroy(this); }
};
