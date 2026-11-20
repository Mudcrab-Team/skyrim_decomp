// Source exposure: binary-analysis; no external implementation source reused.
// Static1772360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772360*);
    virtual void release(Static1772360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772360*);
struct Static1772360 {
    void* value;
    Static1772360();
    ~Static1772360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
