// Source exposure: binary-analysis; no external implementation source reused.
// Static1754860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754860*);
    virtual void release(Static1754860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754860*);
struct Static1754860 {
    void* value;
    Static1754860();
    ~Static1754860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
