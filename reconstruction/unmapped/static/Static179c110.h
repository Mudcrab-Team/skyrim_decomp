// Source exposure: binary-analysis; no external implementation source reused.
// Static179c110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c110*);
    virtual void release(Static179c110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c110*);
struct Static179c110 {
    void* value;
    Static179c110();
    ~Static179c110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
