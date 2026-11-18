// Source exposure: binary-analysis
// Static101620, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101620;
extern void construct(Static101620*, const Descriptor*);
extern void destroy(Static101620*);
struct Static101620 {
    void* value;
    Static101620() { construct(this, &descriptor); }
    ~Static101620() { destroy(this); }
};
