// Source exposure: binary-analysis; no external implementation source reused.
// Static17c6880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c6880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c6880*);
    virtual void release(Static17c6880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c6880*);
struct Static17c6880 {
    void* value;
    Static17c6880();
    ~Static17c6880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
