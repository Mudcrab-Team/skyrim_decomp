// Source exposure: binary-analysis
// Static23c90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static23c90;
extern void construct(Static23c90*, const Descriptor*);
extern void destroy(Static23c90*);
struct Static23c90 {
    void* value;
    Static23c90() { construct(this, &descriptor); }
    ~Static23c90() { destroy(this); }
};
