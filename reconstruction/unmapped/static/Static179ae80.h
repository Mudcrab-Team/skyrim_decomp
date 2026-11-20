// Source exposure: binary-analysis; no external implementation source reused.
// Static179ae80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ae80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ae80*);
    virtual void release(Static179ae80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ae80*);
struct Static179ae80 {
    void* value;
    Static179ae80();
    ~Static179ae80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
