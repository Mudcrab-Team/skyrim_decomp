// Source exposure: binary-analysis; no external implementation source reused.
// Static1786180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786180*);
    virtual void release(Static1786180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786180*);
struct Static1786180 {
    void* value;
    Static1786180();
    ~Static1786180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
