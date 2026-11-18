// Source exposure: binary-analysis; no external implementation source reused.
// Static1777220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777220*);
    virtual void release(Static1777220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777220*);
struct Static1777220 {
    void* value;
    Static1777220();
    ~Static1777220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
