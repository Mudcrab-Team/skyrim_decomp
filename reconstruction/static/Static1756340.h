// Source exposure: binary-analysis; no external implementation source reused.
// Static1756340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756340*);
    virtual void release(Static1756340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756340*);
struct Static1756340 {
    void* value;
    Static1756340();
    ~Static1756340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
