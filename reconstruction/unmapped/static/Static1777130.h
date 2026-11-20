// Source exposure: binary-analysis; no external implementation source reused.
// Static1777130, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777130;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777130*);
    virtual void release(Static1777130*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777130*);
struct Static1777130 {
    void* value;
    Static1777130();
    ~Static1777130() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
