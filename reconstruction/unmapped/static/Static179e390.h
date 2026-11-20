// Source exposure: binary-analysis; no external implementation source reused.
// Static179e390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e390*);
    virtual void release(Static179e390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e390*);
struct Static179e390 {
    void* value;
    Static179e390();
    ~Static179e390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
