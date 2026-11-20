// Source exposure: binary-analysis
// Static1d920, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d920;
extern void construct(Static1d920*, const Descriptor*);
extern void destroy(Static1d920*);
struct Static1d920 {
    void* value;
    Static1d920() { construct(this, &descriptor); }
    ~Static1d920() { destroy(this); }
};
