// Source exposure: binary-analysis; no external implementation source reused.
// Static17c4390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c4390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c4390*);
    virtual void release(Static17c4390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c4390*);
struct Static17c4390 {
    void* value;
    Static17c4390();
    ~Static17c4390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
