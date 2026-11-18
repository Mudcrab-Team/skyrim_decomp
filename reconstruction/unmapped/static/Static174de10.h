// Source exposure: binary-analysis; no external implementation source reused.
// Static174de10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174de10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174de10*);
    virtual void release(Static174de10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174de10*);
struct Static174de10 {
    void* value;
    Static174de10();
    ~Static174de10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
