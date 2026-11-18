// Source exposure: binary-analysis; no external implementation source reused.
// Static17c3430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c3430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c3430*);
    virtual void release(Static17c3430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c3430*);
struct Static17c3430 {
    void* value;
    Static17c3430();
    ~Static17c3430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
