// Source exposure: binary-analysis; no external implementation source reused.
// Static1763e00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763e00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763e00*);
    virtual void release(Static1763e00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763e00*);
struct Static1763e00 {
    void* value;
    Static1763e00();
    ~Static1763e00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
