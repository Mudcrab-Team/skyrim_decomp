// Source exposure: binary-analysis; no external implementation source reused.
// Static1758960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758960*);
    virtual void release(Static1758960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758960*);
struct Static1758960 {
    void* value;
    Static1758960();
    ~Static1758960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
