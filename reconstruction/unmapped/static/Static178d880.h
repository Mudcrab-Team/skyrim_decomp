// Source exposure: binary-analysis; no external implementation source reused.
// Static178d880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d880*);
    virtual void release(Static178d880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d880*);
struct Static178d880 {
    void* value;
    Static178d880();
    ~Static178d880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
