// Source exposure: binary-analysis; no external implementation source reused.
// Static17ade30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ade30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ade30*);
    virtual void release(Static17ade30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ade30*);
struct Static17ade30 {
    void* value;
    Static17ade30();
    ~Static17ade30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
