// Source exposure: binary-analysis; no external implementation source reused.
// Static17c1030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c1030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c1030*);
    virtual void release(Static17c1030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c1030*);
struct Static17c1030 {
    void* value;
    Static17c1030();
    ~Static17c1030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
