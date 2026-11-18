// Source exposure: binary-analysis
// Static16410, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static16410;
extern void construct(Static16410*, const Descriptor*);
extern void destroy(Static16410*);
struct Static16410 {
    void* value;
    Static16410() { construct(this, &descriptor); }
    ~Static16410() { destroy(this); }
};
