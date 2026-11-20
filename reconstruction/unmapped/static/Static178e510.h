// Source exposure: binary-analysis; no external implementation source reused.
// Static178e510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178e510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178e510*);
    virtual void release(Static178e510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178e510*);
struct Static178e510 {
    void* value;
    Static178e510();
    ~Static178e510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
