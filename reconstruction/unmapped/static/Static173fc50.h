// Source exposure: binary-analysis; no external implementation source reused.
// Static173fc50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173fc50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173fc50*);
    virtual void release(Static173fc50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173fc50*);
struct Static173fc50 {
    void* value;
    Static173fc50();
    ~Static173fc50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
