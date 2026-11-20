// Source exposure: binary-analysis
// Static101290, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101290;
extern void construct(Static101290*, const Descriptor*);
extern void destroy(Static101290*);
struct Static101290 {
    void* value;
    Static101290() { construct(this, &descriptor); }
    ~Static101290() { destroy(this); }
};
