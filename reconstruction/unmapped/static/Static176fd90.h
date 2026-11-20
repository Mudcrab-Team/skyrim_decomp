// Source exposure: binary-analysis; no external implementation source reused.
// Static176fd90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fd90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fd90*);
    virtual void release(Static176fd90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fd90*);
struct Static176fd90 {
    void* value;
    Static176fd90();
    ~Static176fd90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
