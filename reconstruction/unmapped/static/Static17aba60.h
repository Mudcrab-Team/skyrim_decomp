// Source exposure: binary-analysis; no external implementation source reused.
// Static17aba60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aba60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aba60*);
    virtual void release(Static17aba60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aba60*);
struct Static17aba60 {
    void* value;
    Static17aba60();
    ~Static17aba60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
