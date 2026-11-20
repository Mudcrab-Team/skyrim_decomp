// Source exposure: binary-analysis; no external implementation source reused.
// Static178cc90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cc90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cc90*);
    virtual void release(Static178cc90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cc90*);
struct Static178cc90 {
    void* value;
    Static178cc90();
    ~Static178cc90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
