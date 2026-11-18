// Source exposure: binary-analysis; no external implementation source reused.
// Static175ae40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ae40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ae40*);
    virtual void release(Static175ae40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ae40*);
struct Static175ae40 {
    void* value;
    Static175ae40();
    ~Static175ae40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
