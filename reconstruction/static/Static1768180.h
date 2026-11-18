// Source exposure: binary-analysis; no external implementation source reused.
// Static1768180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768180*);
    virtual void release(Static1768180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768180*);
struct Static1768180 {
    void* value;
    Static1768180();
    ~Static1768180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
