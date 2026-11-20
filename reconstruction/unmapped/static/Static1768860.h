// Source exposure: binary-analysis; no external implementation source reused.
// Static1768860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768860*);
    virtual void release(Static1768860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768860*);
struct Static1768860 {
    void* value;
    Static1768860();
    ~Static1768860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
