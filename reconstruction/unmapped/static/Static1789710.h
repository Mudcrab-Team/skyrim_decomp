// Source exposure: binary-analysis; no external implementation source reused.
// Static1789710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789710*);
    virtual void release(Static1789710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789710*);
struct Static1789710 {
    void* value;
    Static1789710();
    ~Static1789710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
