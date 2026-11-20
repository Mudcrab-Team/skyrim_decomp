// Source exposure: binary-analysis
// Static101410, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101410;
extern void construct(Static101410*, const Descriptor*);
extern void destroy(Static101410*);
struct Static101410 {
    void* value;
    Static101410() { construct(this, &descriptor); }
    ~Static101410() { destroy(this); }
};
