// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab650*);
    virtual void release(Static17ab650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab650*);
struct Static17ab650 {
    void* value;
    Static17ab650();
    ~Static17ab650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
