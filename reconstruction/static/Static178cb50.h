// Source exposure: binary-analysis; no external implementation source reused.
// Static178cb50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cb50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cb50*);
    virtual void release(Static178cb50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cb50*);
struct Static178cb50 {
    void* value;
    Static178cb50();
    ~Static178cb50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
