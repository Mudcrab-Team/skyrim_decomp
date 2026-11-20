// Source exposure: binary-analysis; no external implementation source reused.
// Static1781860, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781860;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781860*);
    virtual void release(Static1781860*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781860*);
struct Static1781860 {
    void* value;
    Static1781860();
    ~Static1781860() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
