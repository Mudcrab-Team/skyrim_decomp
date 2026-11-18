// Source exposure: binary-analysis; no external implementation source reused.
// Static175db40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175db40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175db40*);
    virtual void release(Static175db40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175db40*);
struct Static175db40 {
    void* value;
    Static175db40();
    ~Static175db40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
