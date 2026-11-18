// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad430*);
    virtual void release(Static17ad430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad430*);
struct Static17ad430 {
    void* value;
    Static17ad430();
    ~Static17ad430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
