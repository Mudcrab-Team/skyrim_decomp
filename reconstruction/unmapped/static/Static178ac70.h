// Source exposure: binary-analysis; no external implementation source reused.
// Static178ac70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ac70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ac70*);
    virtual void release(Static178ac70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ac70*);
struct Static178ac70 {
    void* value;
    Static178ac70();
    ~Static178ac70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
