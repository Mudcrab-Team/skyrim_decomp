// Source exposure: binary-analysis; no external implementation source reused.
// Static176a390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a390*);
    virtual void release(Static176a390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a390*);
struct Static176a390 {
    void* value;
    Static176a390();
    ~Static176a390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
