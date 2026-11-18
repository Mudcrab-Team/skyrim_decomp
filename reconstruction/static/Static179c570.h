// Source exposure: binary-analysis; no external implementation source reused.
// Static179c570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c570*);
    virtual void release(Static179c570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c570*);
struct Static179c570 {
    void* value;
    Static179c570();
    ~Static179c570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
