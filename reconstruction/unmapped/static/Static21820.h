// Source exposure: binary-analysis
// Static21820, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21820;
extern void construct(Static21820*, const Descriptor*);
extern void destroy(Static21820*);
struct Static21820 {
    void* value;
    Static21820() { construct(this, &descriptor); }
    ~Static21820() { destroy(this); }
};
