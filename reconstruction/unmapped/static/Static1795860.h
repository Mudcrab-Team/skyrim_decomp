// Source exposure: binary-analysis; no external implementation source reused.
// Static1795860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1795860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1795860*);
    virtual void release(Static1795860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1795860*);
struct Static1795860 {
    void* value;
    Static1795860();
    ~Static1795860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
