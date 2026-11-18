// Source exposure: binary-analysis; no external implementation source reused.
// Static179e090, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e090;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e090*);
    virtual void release(Static179e090*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e090*);
struct Static179e090 {
    void* value;
    Static179e090();
    ~Static179e090() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
