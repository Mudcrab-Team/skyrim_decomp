// Source exposure: binary-analysis; no external implementation source reused.
// Static178cb00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cb00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cb00*);
    virtual void release(Static178cb00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cb00*);
struct Static178cb00 {
    void* value;
    Static178cb00();
    ~Static178cb00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
