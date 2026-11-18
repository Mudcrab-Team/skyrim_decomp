// Source exposure: binary-analysis
// Static15970, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15970;
extern void construct(Static15970*, const Descriptor*);
extern void destroy(Static15970*);
struct Static15970 {
    void* value;
    Static15970() { construct(this, &descriptor); }
    ~Static15970() { destroy(this); }
};
