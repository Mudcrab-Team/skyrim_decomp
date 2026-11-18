// Source exposure: binary-analysis; no external implementation source reused.
// Static179ad90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ad90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ad90*);
    virtual void release(Static179ad90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ad90*);
struct Static179ad90 {
    void* value;
    Static179ad90();
    ~Static179ad90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
