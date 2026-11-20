// Source exposure: binary-analysis; no external implementation source reused.
// Static178d650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d650*);
    virtual void release(Static178d650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d650*);
struct Static178d650 {
    void* value;
    Static178d650();
    ~Static178d650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
