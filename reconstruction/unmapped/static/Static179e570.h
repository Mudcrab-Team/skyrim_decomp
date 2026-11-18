// Source exposure: binary-analysis; no external implementation source reused.
// Static179e570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e570*);
    virtual void release(Static179e570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e570*);
struct Static179e570 {
    void* value;
    Static179e570();
    ~Static179e570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
