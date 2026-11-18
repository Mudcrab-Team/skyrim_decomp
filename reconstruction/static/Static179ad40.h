// Source exposure: binary-analysis; no external implementation source reused.
// Static179ad40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ad40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ad40*);
    virtual void release(Static179ad40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ad40*);
struct Static179ad40 {
    void* value;
    Static179ad40();
    ~Static179ad40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
