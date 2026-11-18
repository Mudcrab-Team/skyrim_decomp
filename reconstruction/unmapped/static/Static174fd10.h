// Source exposure: binary-analysis; no external implementation source reused.
// Static174fd10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fd10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fd10*);
    virtual void release(Static174fd10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fd10*);
struct Static174fd10 {
    void* value;
    Static174fd10();
    ~Static174fd10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
