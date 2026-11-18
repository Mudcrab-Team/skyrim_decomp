// Source exposure: binary-analysis; no external implementation source reused.
// Static17aca60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aca60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aca60*);
    virtual void release(Static17aca60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aca60*);
struct Static17aca60 {
    void* value;
    Static17aca60();
    ~Static17aca60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
