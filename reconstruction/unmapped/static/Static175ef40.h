// Source exposure: binary-analysis; no external implementation source reused.
// Static175ef40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ef40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ef40*);
    virtual void release(Static175ef40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ef40*);
struct Static175ef40 {
    void* value;
    Static175ef40();
    ~Static175ef40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
