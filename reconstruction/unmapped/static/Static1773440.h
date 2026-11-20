// Source exposure: binary-analysis; no external implementation source reused.
// Static1773440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773440*);
    virtual void release(Static1773440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773440*);
struct Static1773440 {
    void* value;
    Static1773440();
    ~Static1773440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
