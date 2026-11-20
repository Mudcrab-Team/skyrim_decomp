// Source exposure: binary-analysis
// Static90030, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static90030;
extern void construct(Static90030*, const Descriptor*);
extern void destroy(Static90030*);
struct Static90030 {
    void* value;
    Static90030() { construct(this, &descriptor); }
    ~Static90030() { destroy(this); }
};
