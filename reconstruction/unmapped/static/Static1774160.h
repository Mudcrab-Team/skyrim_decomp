// Source exposure: binary-analysis; no external implementation source reused.
// Static1774160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774160*);
    virtual void release(Static1774160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774160*);
struct Static1774160 {
    void* value;
    Static1774160();
    ~Static1774160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
