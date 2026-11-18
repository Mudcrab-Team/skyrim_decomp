// Source exposure: binary-analysis
// Static9f050, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f050;
extern void construct(Static9f050*, const Descriptor*);
extern void destroy(Static9f050*);
struct Static9f050 {
    void* value;
    Static9f050() { construct(this, &descriptor); }
    ~Static9f050() { destroy(this); }
};
