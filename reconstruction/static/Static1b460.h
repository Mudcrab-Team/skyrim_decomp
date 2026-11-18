// Source exposure: binary-analysis
// Static1b460, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b460;
extern void construct(Static1b460*, const Descriptor*);
extern void destroy(Static1b460*);
struct Static1b460 {
    void* value;
    Static1b460() { construct(this, &descriptor); }
    ~Static1b460() { destroy(this); }
};
