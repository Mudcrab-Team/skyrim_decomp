// Source exposure: binary-analysis; no external implementation source reused.
// Static1774020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774020*);
    virtual void release(Static1774020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774020*);
struct Static1774020 {
    void* value;
    Static1774020();
    ~Static1774020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
