// Source exposure: binary-analysis; no external implementation source reused.
// Static1777720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777720*);
    virtual void release(Static1777720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777720*);
struct Static1777720 {
    void* value;
    Static1777720();
    ~Static1777720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
