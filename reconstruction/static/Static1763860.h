// Source exposure: binary-analysis; no external implementation source reused.
// Static1763860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763860*);
    virtual void release(Static1763860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763860*);
struct Static1763860 {
    void* value;
    Static1763860();
    ~Static1763860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
