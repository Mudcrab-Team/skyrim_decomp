// Source exposure: binary-analysis
// Static92f20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static92f20;
extern void construct(Static92f20*, const Descriptor*);
extern void destroy(Static92f20*);
struct Static92f20 {
    void* value;
    Static92f20() { construct(this, &descriptor); }
    ~Static92f20() { destroy(this); }
};
