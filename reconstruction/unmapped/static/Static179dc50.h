// Source exposure: binary-analysis; no external implementation source reused.
// Static179dc50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179dc50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179dc50*);
    virtual void release(Static179dc50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179dc50*);
struct Static179dc50 {
    void* value;
    Static179dc50();
    ~Static179dc50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
