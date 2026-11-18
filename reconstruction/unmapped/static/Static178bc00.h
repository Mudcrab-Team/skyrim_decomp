// Source exposure: binary-analysis; no external implementation source reused.
// Static178bc00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178bc00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178bc00*);
    virtual void release(Static178bc00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178bc00*);
struct Static178bc00 {
    void* value;
    Static178bc00();
    ~Static178bc00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
