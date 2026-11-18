// Source exposure: binary-analysis; no external implementation source reused.
// Static1760160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760160*);
    virtual void release(Static1760160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760160*);
struct Static1760160 {
    void* value;
    Static1760160();
    ~Static1760160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
