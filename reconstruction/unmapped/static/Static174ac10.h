// Source exposure: binary-analysis; no external implementation source reused.
// Static174ac10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ac10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ac10*);
    virtual void release(Static174ac10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ac10*);
struct Static174ac10 {
    void* value;
    Static174ac10();
    ~Static174ac10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
