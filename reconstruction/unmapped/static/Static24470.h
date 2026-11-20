// Source exposure: binary-analysis
// Static24470, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24470;
extern void construct(Static24470*, const Descriptor*);
extern void destroy(Static24470*);
struct Static24470 {
    void* value;
    Static24470() { construct(this, &descriptor); }
    ~Static24470() { destroy(this); }
};
