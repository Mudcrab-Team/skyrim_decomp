// Source exposure: binary-analysis; no external implementation source reused.
// Static174fd60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fd60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fd60*);
    virtual void release(Static174fd60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fd60*);
struct Static174fd60 {
    void* value;
    Static174fd60();
    ~Static174fd60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
