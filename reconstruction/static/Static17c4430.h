// Source exposure: binary-analysis; no external implementation source reused.
// Static17c4430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c4430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c4430*);
    virtual void release(Static17c4430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c4430*);
struct Static17c4430 {
    void* value;
    Static17c4430();
    ~Static17c4430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
