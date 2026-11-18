// Source exposure: binary-analysis; no external implementation source reused.
// Static1740180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740180*);
    virtual void release(Static1740180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740180*);
struct Static1740180 {
    void* value;
    Static1740180();
    ~Static1740180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
