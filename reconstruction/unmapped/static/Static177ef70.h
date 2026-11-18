// Source exposure: binary-analysis; no external implementation source reused.
// Static177ef70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ef70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ef70*);
    virtual void release(Static177ef70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ef70*);
struct Static177ef70 {
    void* value;
    Static177ef70();
    ~Static177ef70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
