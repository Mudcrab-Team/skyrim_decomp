// Source exposure: binary-analysis; no external implementation source reused.
// Static178bd90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178bd90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178bd90*);
    virtual void release(Static178bd90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178bd90*);
struct Static178bd90 {
    void* value;
    Static178bd90();
    ~Static178bd90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
