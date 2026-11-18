// Source exposure: binary-analysis; no external implementation source reused.
// Static177d300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d300*);
    virtual void release(Static177d300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d300*);
struct Static177d300 {
    void* value;
    Static177d300();
    ~Static177d300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
