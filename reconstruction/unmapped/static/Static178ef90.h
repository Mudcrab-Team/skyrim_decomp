// Source exposure: binary-analysis; no external implementation source reused.
// Static178ef90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ef90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ef90*);
    virtual void release(Static178ef90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ef90*);
struct Static178ef90 {
    void* value;
    Static178ef90();
    ~Static178ef90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
