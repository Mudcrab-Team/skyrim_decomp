// Source exposure: binary-analysis; no external implementation source reused.
// Static1789440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789440*);
    virtual void release(Static1789440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789440*);
struct Static1789440 {
    void* value;
    Static1789440();
    ~Static1789440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
