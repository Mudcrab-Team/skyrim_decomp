// Source exposure: binary-analysis; no external implementation source reused.
// Static179dd80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179dd80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179dd80*);
    virtual void release(Static179dd80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179dd80*);
struct Static179dd80 {
    void* value;
    Static179dd80();
    ~Static179dd80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
