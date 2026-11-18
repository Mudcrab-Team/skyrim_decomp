// Source exposure: binary-analysis; no external implementation source reused.
// Static179ea90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ea90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ea90*);
    virtual void release(Static179ea90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ea90*);
struct Static179ea90 {
    void* value;
    Static179ea90();
    ~Static179ea90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
