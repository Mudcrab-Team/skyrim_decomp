// Source exposure: binary-analysis; no external implementation source reused.
// Static178cd30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cd30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cd30*);
    virtual void release(Static178cd30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cd30*);
struct Static178cd30 {
    void* value;
    Static178cd30();
    ~Static178cd30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
