// Source exposure: binary-analysis; no external implementation source reused.
// Static1740aa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740aa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740aa0*);
    virtual void release(Static1740aa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740aa0*);
struct Static1740aa0 {
    void* value;
    Static1740aa0();
    ~Static1740aa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
