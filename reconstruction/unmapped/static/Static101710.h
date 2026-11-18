// Source exposure: binary-analysis
// Static101710, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101710;
extern void construct(Static101710*, const Descriptor*);
extern void destroy(Static101710*);
struct Static101710 {
    void* value;
    Static101710() { construct(this, &descriptor); }
    ~Static101710() { destroy(this); }
};
