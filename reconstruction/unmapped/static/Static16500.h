// Source exposure: binary-analysis
// Static16500, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static16500;
extern void construct(Static16500*, const Descriptor*);
extern void destroy(Static16500*);
struct Static16500 {
    void* value;
    Static16500() { construct(this, &descriptor); }
    ~Static16500() { destroy(this); }
};
