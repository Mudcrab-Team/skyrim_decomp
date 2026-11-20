// Source exposure: binary-analysis; no external implementation source reused.
// Static1768270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768270*);
    virtual void release(Static1768270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768270*);
struct Static1768270 {
    void* value;
    Static1768270();
    ~Static1768270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
