// Source exposure: binary-analysis
// Static108030, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108030;
extern void construct(Static108030*, const Descriptor*);
extern void destroy(Static108030*);
struct Static108030 {
    void* value;
    Static108030() { construct(this, &descriptor); }
    ~Static108030() { destroy(this); }
};
