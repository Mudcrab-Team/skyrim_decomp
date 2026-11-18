// Source exposure: binary-analysis
// Static18070, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static18070;
extern void construct(Static18070*, const Descriptor*);
extern void destroy(Static18070*);
struct Static18070 {
    void* value;
    Static18070() { construct(this, &descriptor); }
    ~Static18070() { destroy(this); }
};
