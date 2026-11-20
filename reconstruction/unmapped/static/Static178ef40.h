// Source exposure: binary-analysis; no external implementation source reused.
// Static178ef40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ef40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ef40*);
    virtual void release(Static178ef40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ef40*);
struct Static178ef40 {
    void* value;
    Static178ef40();
    ~Static178ef40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
