// Source exposure: binary-analysis
// Static15310, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15310;
extern void construct(Static15310*, const Descriptor*);
extern void destroy(Static15310*);
struct Static15310 {
    void* value;
    Static15310() { construct(this, &descriptor); }
    ~Static15310() { destroy(this); }
};
