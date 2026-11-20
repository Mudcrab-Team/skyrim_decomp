// Source exposure: binary-analysis
// Static101470, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101470;
extern void construct(Static101470*, const Descriptor*);
extern void destroy(Static101470*);
struct Static101470 {
    void* value;
    Static101470() { construct(this, &descriptor); }
    ~Static101470() { destroy(this); }
};
