// Source exposure: binary-analysis; no external implementation source reused.
// Static1778440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778440*);
    virtual void release(Static1778440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778440*);
struct Static1778440 {
    void* value;
    Static1778440();
    ~Static1778440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
