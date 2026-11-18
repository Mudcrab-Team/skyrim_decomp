// Source exposure: binary-analysis; no external implementation source reused.
// Static178bc50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178bc50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178bc50*);
    virtual void release(Static178bc50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178bc50*);
struct Static178bc50 {
    void* value;
    Static178bc50();
    ~Static178bc50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
