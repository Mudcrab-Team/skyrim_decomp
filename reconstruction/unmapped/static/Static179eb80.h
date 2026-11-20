// Source exposure: binary-analysis; no external implementation source reused.
// Static179eb80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179eb80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179eb80*);
    virtual void release(Static179eb80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179eb80*);
struct Static179eb80 {
    void* value;
    Static179eb80();
    ~Static179eb80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
