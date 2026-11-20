// Source exposure: binary-analysis; no external implementation source reused.
// Static174de60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174de60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174de60*);
    virtual void release(Static174de60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174de60*);
struct Static174de60 {
    void* value;
    Static174de60();
    ~Static174de60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
