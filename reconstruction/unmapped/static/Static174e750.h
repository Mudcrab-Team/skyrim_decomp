// Source exposure: binary-analysis; no external implementation source reused.
// Static174e750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e750*);
    virtual void release(Static174e750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e750*);
struct Static174e750 {
    void* value;
    Static174e750();
    ~Static174e750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
