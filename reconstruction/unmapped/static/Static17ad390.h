// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad390*);
    virtual void release(Static17ad390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad390*);
struct Static17ad390 {
    void* value;
    Static17ad390();
    ~Static17ad390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
