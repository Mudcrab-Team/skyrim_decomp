// Source exposure: binary-analysis
// Static23c30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23c30;
extern void construct(Static23c30*, const Descriptor*);
extern void destroy(Static23c30*);
struct Static23c30 {
    void* value;
    Static23c30() { construct(this, &descriptor); }
    ~Static23c30() { destroy(this); }
};
