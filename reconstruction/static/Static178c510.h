// Source exposure: binary-analysis; no external implementation source reused.
// Static178c510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c510*);
    virtual void release(Static178c510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c510*);
struct Static178c510 {
    void* value;
    Static178c510();
    ~Static178c510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
