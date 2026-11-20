// Source exposure: binary-analysis; no external implementation source reused.
// Static174ac60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ac60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ac60*);
    virtual void release(Static174ac60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ac60*);
struct Static174ac60 {
    void* value;
    Static174ac60();
    ~Static174ac60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
