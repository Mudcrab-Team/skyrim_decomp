// Source exposure: binary-analysis; no external implementation source reused.
// Static178fb50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178fb50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178fb50*);
    virtual void release(Static178fb50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178fb50*);
struct Static178fb50 {
    void* value;
    Static178fb50();
    ~Static178fb50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
