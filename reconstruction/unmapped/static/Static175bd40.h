// Source exposure: binary-analysis; no external implementation source reused.
// Static175bd40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bd40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bd40*);
    virtual void release(Static175bd40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bd40*);
struct Static175bd40 {
    void* value;
    Static175bd40();
    ~Static175bd40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
