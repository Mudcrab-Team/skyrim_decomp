// Source exposure: binary-analysis; no external implementation source reused.
// Static1747750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747750*);
    virtual void release(Static1747750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747750*);
struct Static1747750 {
    void* value;
    Static1747750();
    ~Static1747750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
