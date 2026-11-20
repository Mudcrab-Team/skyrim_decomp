// Source exposure: binary-analysis
// Static101680, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101680;
extern void construct(Static101680*, const Descriptor*);
extern void destroy(Static101680*);
struct Static101680 {
    void* value;
    Static101680() { construct(this, &descriptor); }
    ~Static101680() { destroy(this); }
};
