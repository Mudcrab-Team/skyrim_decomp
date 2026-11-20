// Source exposure: binary-analysis; no external implementation source reused.
// Static17a5f60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a5f60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a5f60*);
    virtual void release(Static17a5f60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a5f60*);
struct Static17a5f60 {
    void* value;
    Static17a5f60();
    ~Static17a5f60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
