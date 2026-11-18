// Source exposure: binary-analysis; no external implementation source reused.
// Static178ac20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ac20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ac20*);
    virtual void release(Static178ac20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ac20*);
struct Static178ac20 {
    void* value;
    Static178ac20();
    ~Static178ac20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
