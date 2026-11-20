// Source exposure: binary-analysis; no external implementation source reused.
// Static17b7390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b7390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b7390*);
    virtual void release(Static17b7390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b7390*);
struct Static17b7390 {
    void* value;
    Static17b7390();
    ~Static17b7390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
