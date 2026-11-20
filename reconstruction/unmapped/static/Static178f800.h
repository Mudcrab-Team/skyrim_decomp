// Source exposure: binary-analysis; no external implementation source reused.
// Static178f800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f800*);
    virtual void release(Static178f800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f800*);
struct Static178f800 {
    void* value;
    Static178f800();
    ~Static178f800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
