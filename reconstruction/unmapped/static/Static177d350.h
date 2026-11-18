// Source exposure: binary-analysis; no external implementation source reused.
// Static177d350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d350*);
    virtual void release(Static177d350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d350*);
struct Static177d350 {
    void* value;
    Static177d350();
    ~Static177d350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
