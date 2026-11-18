// Source exposure: binary-analysis; no external implementation source reused.
// Static1773120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773120*);
    virtual void release(Static1773120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773120*);
struct Static1773120 {
    void* value;
    Static1773120();
    ~Static1773120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
