// Source exposure: binary-analysis; no external implementation source reused.
// Static1774e30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774e30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774e30*);
    virtual void release(Static1774e30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774e30*);
struct Static1774e30 {
    void* value;
    Static1774e30();
    ~Static1774e30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
